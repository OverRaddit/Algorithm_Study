#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 800
#define MAX_E 20000
#define MAX_W 1000
#define INF MAX_E * MAX_W + 1
using namespace std;

int N,E,K;
vector<pair<int,int> > graph[MAX_V + 1];

vector<int> dijkstra(int src) {
  vector<int> dist(N + 1, INF);
  dist[src] = 0;
  priority_queue<pair<int,int> > pq;
  pq.push(make_pair(0, src));

  while(!pq.empty()) {
    int cost = -1 * pq.top().first;
    int here = pq.top().second;
    pq.pop(); // pop하는 것을 항상 까먹는군 ㅎㅎ;;

    if(dist[here] < cost) continue;
    for(int i=0;i<graph[here].size();i++) {
      int there = graph[here][i].first;
      int nextDist = cost + graph[here][i].second;

      if (dist[there] > nextDist) {
        dist[there] = nextDist;
        pq.push(make_pair(-nextDist, there));
      }
    }
  }

  return dist;
}

int main()
{
  // INPUT
  cin >> N >> E;
  int u,v,w;
  for(int i=0;i<E;i++) {
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }
  int v1,v2;
  cin >> v1 >> v2;

  // PROCESSS
  // 생각해보니 v1 -> v2의 최단경로가 다른점을 경유할수있음을 간과했다.
  vector<int> fromStart = dijkstra(1);
  vector<int> fromV1 = dijkstra(v1);
  vector<int> fromV2 = dijkstra(v2);

  int answer = 0,path1,path2;
  // 1 -> v1 -> v2 -> N
  path1 = fromStart[v1] + fromV1[v2] + fromV2[N];
  // 1 -> v2 -> v1 -> N
  path2 = fromStart[v2] + fromV2[v1] + fromV1[N];

  // OUTPUT
  answer = min(path1, path2);
  if (answer >= INF)
    cout << "-1\n";
  else
    cout << answer << "\n";
}

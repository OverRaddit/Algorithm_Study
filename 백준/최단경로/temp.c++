#include <iostream>
#include <queue>
#include <vector>
#define MAX_V 800
#define MAX_E 200000
#define MAX_W 1000
#define INF MAX_E * MAX_W + 1
using namespace std;

int N,E,v1,v2;
vector<pair<int,int> > graph[MAX_V + 1];

vector<int> dijkstra(int src) {
  vector<int> dist(N+1, INF);
  priority_queue<pair<int,int> > pq;

  dist[src] = 0;
  pq.push(make_pair(0, src));

  while(!pq.empty()) {
    int cost = -1 * pq.top().first;
    int here = pq.top().second;
    pq.pop();

    if (cost > dist[here]) continue;
    for(int i=0;i<graph[here].size();i++) {
      int there = graph[here][i].first;
      int nextDist = cost + graph[here][i].second;

      if (nextDist < dist[there]) {
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
  int a,b,c;
  for(int i=0;i<E;i++) {
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }
  cin >> v1 >> v2;

  vector<int> fromOne = dijkstra(1);
  vector<int> fromV1 = dijkstra(v1);
  vector<int> fromV2 = dijkstra(v2);

  // 1~v1 + v1~v2 + v2~N
  int path1 = fromOne[v1] + fromV1[v2] + fromV2[N];
  // 1~v2 + v2~v1 + v1~N
  int path2 = fromOne[v2] + fromV2[v1] + fromV1[N];
  int answer = min(path1, path2);

  // OUTPUT
  if (answer >= INF)
    cout << "-1\n";
  else
    cout << answer << "\n";
}

#include <iostream>
#include <vector>
#include <queue>
#define INF 300000 * 10 + 1
using namespace std;

int V,E,K;
vector<pair<int,int> > graph[20000];

vector<int> dijkstra(int src) {
  vector<int> dist(V, INF);
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
  cin >> V >> E;
  cin >> K;
  int u,v,w;
  for(int i=0;i<E;i++) {
    cin >> u >> v >> w;
    graph[u-1].push_back(make_pair(v-1, w));
  }

  // OUTPUT
  vector<int> answer = dijkstra(K-1);
  for(int i=0;i<answer.size();i++) {
    if (answer[i] == INF)
      cout << "INF\n";
    else
      cout << answer[i] << "\n";
  }
}

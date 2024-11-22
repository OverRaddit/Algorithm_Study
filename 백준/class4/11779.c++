#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 10000
#define MAX_E 100000
#define INF MAX_E * 100000 + 1
using namespace std;

int N,M,S,E;
vector<pair<int,int> > graph[MAX_V+1];

vector<pair<int, vector<int> > > dijkstra(int src) {
  vector<pair<int, vector<int> > > dist(N + 1, make_pair(INF, vector<int>()));
  priority_queue<pair<int, vector<int> > > pq;

  vector<int> initialPath;
  initialPath.push_back(src);
  pq.push(make_pair(0, initialPath));
  dist[src] = make_pair(0 , initialPath);

  while(!pq.empty()) {
    int cost = -1 * pq.top().first;
    vector<int> path = pq.top().second;
    int here = path.back();
    pq.pop(); // pop하는 것을 항상 까먹는군 ㅎㅎ;;

    if(dist[here].first < cost) continue;
    for(int i=0;i<graph[here].size();i++) {
      int there = graph[here][i].first;
      int nextDist = cost + graph[here][i].second;

      if (dist[there].first > nextDist) {
        vector<int> newPath = path;
        newPath.push_back(there);
        dist[there] = make_pair(nextDist, newPath);
        pq.push(make_pair(-nextDist, newPath));
      }
    }
  }

  return dist;
}


int main()
{
  // INPUT
  cin >> N >> M;
  int u,v,w;
  for(int i=0;i<M;i++) {
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v,w));
  }
  cin >> S >> E;

  vector<pair<int, vector<int> > > dist = dijkstra(S);
  cout << dist[E].first << "\n";
  cout << dist[E].second.size() << "\n";
  for(int i=0;i<dist[E].second.size();i++) {
    cout << dist[E].second[i] << " ";
  }
  cout << "\n";
}

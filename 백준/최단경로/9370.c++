#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_V 2000
#define MAX_E 50000
#define MAX_W 1000
#define INF MAX_E * MAX_W + 1
using namespace std;

int T;

vector<int> dijkstra(int src, int n, vector<pair<int,int> > graph[]) {
  vector<int> dist(n+1, INF);
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
  cin >> T;
  for(int x=0;x<T;x++) {
    vector<pair<int,int> > graph[MAX_V + 1];
    int n,m,t;
    cin >> n >> m >> t;
    int s,g,h, a,b,d; // 출발지, g-h는 반드시지남
    cin >> s >> g >> h;
    for(int i=0;i<m;i++) {
      cin >> a >> b >> d;
      graph[a].push_back(make_pair(b, d));
      graph[b].push_back(make_pair(a, d));
    }
    vector<int> candidate(t, 0);
    vector<int> validate;
    for(int i=0;i<t;i++) {
      cin >> candidate[i];
    }

    // 시작지점에서 각 후보지들로 가는 최단경로에 g-h가 포함되었다면 validate에 담는다.
    vector<int> dist = dijkstra(s, n, graph);
    vector<int> fromG = dijkstra(g, n, graph);
    vector<int> fromH = dijkstra(h, n, graph);

    for(int i=0;i<t;i++) {
      int path1 = dist[g] + fromG[h] + fromH[candidate[i]];
      int path2 = dist[h] + fromH[g] + fromG[candidate[i]];
      int minWeight = min(path1, path2);
      if (minWeight == dist[candidate[i]])
        validate.push_back(candidate[i]);
    }

    sort(validate.begin(), validate.end());
    for(int i=0;i<validate.size();i++) {
      cout << validate[i] << " ";
    }
    cout << "\n";
  }
}

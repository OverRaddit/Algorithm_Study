#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX_V 1000
using namespace std;


int N,M,X,answer=-1;
vector<pair<int,int> > graph[MAX_V];

vector<int> dijkstra(int src) {
  priority_queue<pair<int,int> > pq;
  vector<int> dist(N, INT_MAX);
  dist[src] = 0;
  pq.push(make_pair(0, src));

  while(!pq.empty()) {
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    if(dist[here] < cost) continue;
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
  cin >> N >> M >> X;
  // graph.resize(N);
  for(int i=0;i<M;i++) {
    int u,v,t;
    cin >> u >> v >> t;
    graph[u-1].push_back(make_pair(v-1, t)); // num to idx
  }

  // X의 집~ 각자집거리 구하기
  vector<int> XtoEach = dijkstra(X-1);

  // 자기집 ~ X의 집거리 구하기
  for(int i=0;i<N;i++) {
    vector<int> ItoEach = dijkstra(i);
    answer = max(answer, XtoEach[i] + ItoEach[X-1]);
  }

  // OUTPUT
  cout << answer << endl;
}

#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 100
#define INF 987654321 // ???
using namespace std;

int n,m,r, answer=0;
vector<pair<int,int> > graph[MAX_V];
vector<int> itemCount;

// 다익스트라 결과배열에서 sum만 하면되네;;;
int dijkstra(int src) {
  vector<int> dist(n, INF);
  priority_queue<pair<int,int> > pq;

  dist[src] = 0;
  pq.push(make_pair(0, src));

  while(!pq.empty()) {
    int cost = -1 * pq.top().first;
    int here = pq.top().second;
    pq.pop();

    if (dist[here] < cost) continue;
    for(int i=0;i<graph[here].size();i++) {
      int there = graph[here][i].first;
      int nextDist = cost + graph[here][i].second;

      if (nextDist <= m && nextDist < dist[there]) {
        dist[there] = nextDist;
        pq.push(make_pair(-nextDist, there));
      }
    }
  }

  int sum = 0;
  for(int i=0;i<n;i++)
    sum += (dist[i] <= m) ? itemCount[i] : 0;
  return sum;
}

int main()
{
  // INPUT
  cin >> n >> m >> r; // 지역V, 수색범위, 길의개수E
  itemCount.resize(n);
  for(int i=0;i<n;i++) {
    cin >> itemCount[i];
  }
  int a,b,I;
  for(int i=0;i<r;i++) { // 양방향
    cin >> a >> b >> I;
    graph[a-1].push_back(make_pair(b-1, I));
    graph[b-1].push_back(make_pair(a-1, I));
  }

  // PROCESS - 모든 점들에 대해 다익스트라 탐색 -> 최대 아이템개수 answer를 갱신한다.
  for(int i=0;i<n;i++)
    answer = max(answer, dijkstra(i));

  // OUTPUT
  cout << answer << endl;
}

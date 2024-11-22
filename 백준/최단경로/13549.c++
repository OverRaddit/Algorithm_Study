#include <iostream>
#include <vector>
#include <queue>
// #define INF 300000 * 10 + 1 // ???
#define INF 987654321
#define MAX_V 100000
using namespace std;

int N,K;
vector<pair<int,int> > graph[MAX_V + 1];

vector<int> dijkstra(int src) {
  vector<int> dist(MAX_V + 1, INF);
  dist[src] = 0;
  priority_queue<pair<int,int> > pq;
  pq.push(make_pair(0, src));

  while(!pq.empty()) {
    int cost = -1 * pq.top().first;
    int here = pq.top().second;
    pq.pop(); // pop하는 것을 항상 까먹는군 ㅎㅎ;;

    if(dist[here] < cost) continue;

    // walk
    if (here+1 <= MAX_V && dist[here+1] > cost + 1) {
      dist[here+1] = cost + 1;
      pq.push(make_pair((cost+1)*-1, here+1));
    }
    if (here-1 >= 0 && dist[here-1] > cost + 1) {
      dist[here-1] = cost + 1;
      pq.push(make_pair((cost+1)*-1, here-1));
    }

    // teleport
    // outofbounds 방지를 위한 구간설정.
    if (here*2 <= MAX_V && dist[here*2] > cost) {
      dist[here*2] = cost;
      pq.push(make_pair(cost*-1, here*2));
    }
  }

  return dist;
}

int main()
{
  // INPUT
  cin >> N >> K;

  vector<int> fromSubin = dijkstra(N);
  cout << fromSubin[K] << "\n";
}

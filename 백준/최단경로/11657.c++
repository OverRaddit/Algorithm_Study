#include <iostream>
#include <vector>
#define MAX_V 500
#define MAX_E 6000
#define MAX_W 10000
// #define INF MAX_E * MAX_W + 1 // 이값을 어떻게 설정해야할지 헷갈려..
#define INF 1e18 // 이값을 어떻게 설정해야할지 헷갈려..
#define ll long long
using namespace std;

int N,M;
vector<pair<int,int> > graph[MAX_V];

vector<ll> bellmanFord(int src) {
  vector<ll> upper(N, INF);
  upper[src] = 0;

  for(int iter=0;iter<N;iter++) {
    for(int here=0;here<N;here++) {
      for(int j=0;j<graph[here].size();j++) {
        int there = graph[here][j].first;
        int cost = graph[here][j].second;

        if (upper[here] != INF && upper[there] > upper[here] + cost) {
          if (iter == N-1) return vector<ll>(); // N번째 relax가 성공한 경우, 최단경로에 음의사이클이 존재하므로 빈배열반환
          upper[there] = upper[here] + cost;
        }
      }
    }
  }

  // v번째에는 출발지랑 연결되어있는 케이스만 Relax를 적용
  // for(int here=0;here<N;here++) {
  //   for(int j=0;j<graph[here].size();j++) {
  //     int there = graph[here][j].first;
  //     int cost = graph[here][j].second;

  //     if (upper[here] != INF && upper[there] > upper[here] + cost) {
  //       return vector<ll>();
  //     }
  //   }
  // }

  return upper;
}

int main()
{
  // INPUT
  cin >> N >> M;
  int A,B,C;
  for(int i=0;i<M;i++) {
    cin >> A >> B >> C;
    graph[A-1].push_back(make_pair(B-1, C));
  }

  vector<ll> result = bellmanFord(1 -1);

  // OUTPUT
  if(result.empty())
    cout << "-1" << "\n";
  else {
    for(int i=1;i<result.size();i++) {
      if (result[i] == INF)
        cout << "-1\n";
      else
        cout << result[i] << "\n";
    }
  }
}

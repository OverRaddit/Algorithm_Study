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
vector<ll> upper;

// vector<ll> bellmanFord(int src) {
bool bellmanFord(int src) {
  upper[src] = 0;
  bool updated;

  for(int iter=0;iter<N-1;iter++) {
    updated = false;
    for(int here=0;here<N;here++) {
      for(int j=0;j<graph[here].size();j++) {
        int there = graph[here][j].first;
        int cost = graph[here][j].second;

        if (upper[there] != INF && upper[there] > upper[here] + cost) {
          upper[there] = upper[here] + cost;
          updated = true;
        }
      }
    }
    if(!updated) break;
  }

  // v번째에는 출발지랑 연결되어있는 케이스만 Relax를 적용
  for(int here=0;here<N;here++) {
    for(int j=0;j<graph[here].size();j++) {
      int there = graph[here][j].first;
      int cost = graph[here][j].second;

      if (upper[there] != INF && upper[there] > upper[here] + cost) {
        return true;
      }
    }
  }

  if(updated) upper.clear();
  return false;
}

int main()
{
  // INPUT
  cin >> N >> M;
  upper.resize(N, INF);
  int A,B,C;
  for(int i=0;i<M;i++) {
    cin >> A >> B >> C;
    graph[A-1].push_back(make_pair(B-1, C));
  }

  bool isCycle = bellmanFord(1 -1);

  if(isCycle)
    cout << "-1" << "\n";
  else {
    for(int i=1;i<upper.size();i++) {
      if (upper[i] == INF)
        cout << "-1\n";
      else
        cout << upper[i] << "\n";
    }
  }

  // 만약 그래프에 음의 사이클이 존재하는데, 시작점과끝점이 음의사이클과 연결되지않는다면?
}

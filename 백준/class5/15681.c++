#include <iostream>
#include <vector>
#include <cstring>
#define MAX_V 100000
using namespace std;

int N,R,Q;
vector<vector<pair<int,bool> > > graph;
vector<int> answer;
int visited[MAX_V] = {0};

/*
## 수행방식
그냥 그래프를 입력으로 받고, R을 중심으로 visited를 갱신한다.
R을 중심으로 dfs를 수행, 사용된 간선들만 graph에서 사용한다.
나머지는 각 U점에서 dfs를 하되, 위에서 표시한 간선만 사용하여 탐색한 노드의 수를 각각반환한다.

## 알고리즘의 복잡도.
dfs 1회수행
인접리스트니까 O(V+E) ~= O(V) = 10^5
*/

int dfs(int src) {
  int ret = 1;
  visited[src] = true;
  for(int i=0;i<graph[src].size();i++) {
    int there = graph[src][i].first;
    if (visited[there]) continue;
    graph[src][i].second = true; // 루트에서 수행한 경로를 활성화한다.
    visited[there] = dfs(there);
    ret += visited[there];
  }
  visited[src] = ret;
  return ret;
}

int main()
{
  std::ios_base::sync_with_stdio( false );
  std::cin.tie( NULL );
  std::cout.tie( NULL );
  cin >> N >> R >> Q;
  graph.resize(N);
  int u,v;
  for(int i=0;i<N-1;i++) {
    cin >> u >> v;
    // num to idx
    graph[u-1].push_back(make_pair(v-1, false));
    graph[v-1].push_back(make_pair(u-1, false));
  }
  dfs(R-1); // num to idx
  int tmp;
  for(int i=0;i<Q;i++) {
    cin >> tmp;
    answer.push_back(visited[tmp-1]); // num to idx
  }

  // OUTPUT
  for(int n: answer) {
    cout << n << "\n";
  }
}

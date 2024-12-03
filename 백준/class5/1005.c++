#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
// #define INF -1

using namespace std;

int T,N,K,W;
vector<vector<int> > graph;
int visited[1000] = {0};
int dp[1000] = {0};
vector<int> answers;

void dfs(int src, int depth) {
  if (visited[src] != -1) return;
  visited[src] = depth;

  for(int i=0;i<graph[src].size();i++) {
    int there = graph[src][i];
    if (visited[there] != -1) continue;
    dfs(there, depth + 1);
  }
}

void Solve()
{
  // INPUT
  cin >> N >> K;
  vector<int> D(N, 0);
  for(int i=0;i<N;i++) {
    cin >> D[i];
    dp[i] = D[i];
  }
  int u,v;
  graph.clear();
  graph.resize(N);
  for(int i=0;i<K;i++) {
    cin >> u >> v;
    // 방향을 반대로, 0 base로 넣는 것이 뽀인트.
    graph[v-1].push_back(u-1);
  }
  cin >> W;
  memset(visited, -1, sizeof(visited));

  dfs(W-1, 0);
  map<int,vector<int> > group;
  for(int i=0;i<N;i++) {
    int timeStamp = visited[i];
    group[timeStamp].push_back(i);
  }
  int answer = 0;
  for(auto it=group.crbegin(); it!=group.crend();it++) {
    if (it->first <= 0) continue;
    // int maxTime = -1;
    // for(int i=0;i<it->second.size();i++) {
    //   maxTime = max(maxTime, D[it->second[i]]);
    // }
    // answer += maxTime;

  }
  answers.push_back(answer);
}

int main()
{
  cin >> T;
  for(int t=0;t<T;t++) {
    Solve();
  }
  for(int i=0;i<answers.size();i++) {
    cout << answers[i] << "\n";
  }
}
/*

1. dfs

그래프를 입력의 역방향으로 두고 최종건물을 시작점으로 dfs를 수행.
모든 건물을 시작점을 기준으로 몇칸 떨어져있는지 기록.
같은 거리만큼 떨어진 건물들중 가장 건설시간이 큰 녀석들끼리 sum

2.

최종건물에서 같은 거리만큼 떨어진 아이들끼리 비교해선 안됨.
건물을 올리는데 필요한 테크수가 같인 아이들끼리 비교해야함.

dp[i] = i건물을 짓는 최소시간
1차건물 : 1~X에 대하여 dp[i] = arr[i];
N차건물 : 1~X에 대하여 dp[i] = max(dp[?],..,dp[?]) + arr[i]

1) 1~N차건물에 해당하는 자료구조를 어떻게 만들 것인가?
map<int,vector<int> > nthHouse;
2) 각 건물에 필요한 의존성 건물 목록을 어떻게 만들 것인가?
vector<vector<int> > houseDepen;

*/

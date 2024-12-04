#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int T,N,K,W;
vector<int> D;
vector<vector<int> > graph;
vector<pair<int,int> > vertexDegree;
vector<int> dp;
vector<int> answers;
// int dp[1000] = {0};

/*

이 문제가 어려웠던 이유

1. 위상정렬로 각 원소를 순회하는 것과 dp를 업데이트하는 타이밍이 헷갈림.

*/

void topol_sort() {
  queue<int> q;

  for(int i=0;i<vertexDegree.size();i++)
    if (vertexDegree[i].first == 0)
      q.push(i);

  while(!q.empty()) {
    int here = q.front();
    q.pop();
    for(int there: graph[here]) {
      // 이 부분...
      dp[there] = max(dp[there], dp[here] + D[there]);
      vertexDegree[there].first--;
      if (vertexDegree[there].first == 0)
        q.push(there);
    }
  }

}

void Solve()
{
  // INPUT
  cin >> N >> K;
  D.resize(N);
  graph.clear();
  graph.resize(N);
  dp.assign(N, 0); // ?
  vertexDegree.assign(N, make_pair(0,0));
  for(int i=0;i<N;i++) {
    cin >> D[i];
    dp[i] = D[i];
  }
  int u,v;
  for(int i=0;i<K;i++) {
    cin >> u >> v; // u->v간선이 존재.
    graph[u-1].push_back(v-1);
    vertexDegree[v-1].first++;
  }
  cin >> W;
  topol_sort();
  answers.push_back(dp[W-1]);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  for(int t=0;t<T;t++) {
    Solve();
  }
  for(int i=0;i<answers.size();i++) {
    cout << answers[i] << "\n";
  }
}

/*
현재 496ms
-> 빠른입출력 적용하니 144ms
*/

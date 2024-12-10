#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 32000
using namespace std;

int N,M;
int inDegree[MAX_N + 1] = {0};
vector<vector<int> > graph;
vector<int> answer;

void topol_sort()
{
  queue<int> q;

  // indegree가 0인 원소를 큐에 삽입
  for(int i=1;i<=N;i++) {
    if(inDegree[i] == 0) q.push(i);
  }

  while(!q.empty()) {
    int s = q.front();
    q.pop();
    answer.push_back(s);
    for(int there: graph[s]) {
      // 방문
      inDegree[there]--;
      // 큐삽입
      if(inDegree[there] == 0)
        q.push(there);
    }
  }
}

int main()
{
  cin >> N >> M;
  graph.resize(N+1);
  for(int i=0;i<M;i++) {
    int a,b;
    cin >> a >> b;
    graph[a].push_back(b);
    inDegree[b]++;
  }

  topol_sort();

  for(int n: answer)
    cout << n << " ";
  cout << "\n";
}

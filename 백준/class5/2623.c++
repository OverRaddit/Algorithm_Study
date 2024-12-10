#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
vector<int> answer;
vector<vector<int> > v;
vector<vector<int> > graph;
int inDegree[1000 + 1] = {0};

void topol_sort()
{
  queue<int> q;

  for(int i=1;i<=N;i++)
    if (inDegree[i] == 0)
      q.push(i);

  while(!q.empty()){
    int here = q.front();
    q.pop();
    answer.push_back(here);
    for(int there: graph[here]) {
      inDegree[there]--;
      if(inDegree[there] == 0)
        q.push(there);
    }
  }
}

void input_util(vector<int> &v) {
  // for(int i=0;i<v.size()-1;i++) {
  //   for(int j=i+1;j<v.size();j++) {
  //     graph[i].push_back(j);
  //     inDegree[j]++;
  //   }
  // }
  for(int i=0;i<v.size()-1;i++) {
    // a->b의 간선을 표시
    int a = v[i];
    int b = v[i+1];
    inDegree[b]++;
    graph[a].push_back(b);
  }
}

int main()
{
  cin >> N >> M;
  v.resize(M);
  graph.resize(N+1);
  for(int i=0;i<M;i++) {
    int num;
    cin >> num;
    for(int j=0;j<num;j++) {
      int x;
      cin >> x;
      v[i].push_back(x);
    }
    // v[i] 배열에서 서로다른 2쌍의 모든 경우를 찾는다.
    // 각 경우마다 inDegree값과 그래프연결을 표시한다.
    input_util(v[i]);
  }

  topol_sort();
  if(answer.size() != N) {
    cout << 0 << endl;
  }
  else {
    for(int n:answer) {
      cout << n << "\n";
    }
  }
}

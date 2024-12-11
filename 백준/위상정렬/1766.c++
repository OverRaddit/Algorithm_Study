#include <iostream>
#include <vector>
#include <queue>
#define N_MAX 32000
using namespace std;

int N,M;
int inDegree[N_MAX+1] = {0};
vector<vector<int> > graph;
vector<int> answer;

/*
어제 푼 최종순위 문제와 비슷하다.
- 기존순서가 존재하기 때문.
  - 단, 어제 문제는 기존순서에 바뀐순서가 주어졌었다면...
  - 이번문제는 M개의 의존성을 최우선하되 거기에서 작은번호순으로 출력하는것이다.
  - 따라서 이번문제는 기존순서를 의존성으로 추가해서는 안된다. 실제로 예제케이스에서 사이클이 생기게된다.
- N<=32000, 그래프를 인접리스트로 표현한다.
- 위상정렬에서 사용하는 큐를 우선순위큐(최소힙)로 만들면 되지 않을까?
  - 큐에 담긴 원소는 inDegree값이 0인 것들이고 이것들중 최솟값(top)을 뽑아 방문.
  - 이후 top과 연결된 간선을 지운다(top과 연결된 간선들의 inDegree값 차감)
  - 이렇게 되면 위상정렬이면서, 방문할 수 있는 간선들중 가능하면 작은숫자부터 방문하게 된다.
*/

void topol_sort()
{
  // 최소힙 pq
  priority_queue<int, vector<int>, greater<int> > pq;

  for(int i=1;i<=N;i++)
    if (inDegree[i] == 0)
      pq.push(i);

  while(!pq.empty()) {
    int x = pq.top();
    pq.pop();
    answer.push_back(x);

    for(int there: graph[x]) {
      inDegree[there]--;
      if (inDegree[there] == 0)
        pq.push(there);
    }
  }
}

int main()
{
  // INPUT
  cin >> N >> M;
  graph.resize(N+1);
  for(int i=0;i<M;i++) {
    int a,b;
    cin >> a >> b;
    graph[a].push_back(b);
    inDegree[b]++;
  }
  topol_sort();

  // OUTPUT
  for(int x: answer) {
    cout << x << " ";
  }
  cout << "\n";
}

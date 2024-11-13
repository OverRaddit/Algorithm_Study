#include <iostream>
#include <vector>
#include <queue>
# define INPUT_SIZE 50

using namespace std;

int N,M;
int a,b;
int knower[INPUT_SIZE] = {0}; // 진실을 아는 사람의 번호
vector<vector<int> > party;
bool visited[INPUT_SIZE] = {0};
vector<vector<int> > graph;

void bfs(int start) {
  queue<int> q;

  q.push(start);
  visited[start] = 1;

  while(!q.empty()) {
    int here = q.front();
    q.pop();

    for(int i=0;i<graph[here].size();i++) {
      int there = graph[here][i];
      if (!visited[there]) {
        q.push(there);
        visited[there] = 1;
      }
    }
  }
}

int main()
{
  // INPUT
  cin >> N >> M; // 사람수, 파티수
  cin >> a; // 진실러 수, 번호(진실러없으면 생략됨)
  graph.resize(N);
  party.resize(M);
  for(int i=0;i<a;i++) {
    cin >> knower[i];
  }
  for(int i=0;i<M;i++) {
    int num;
    cin >> num;
    for(int j=0;j<num;j++) {
      int tmp;
      cin >> tmp;
      party[i].push_back(tmp-1); // num to idx
    }
  }

  // create graph
  for(int i=0;i<M;i++) {
    for(int j=0;j<party[i].size();j++) {
      for(int k=j+1;k<party[i].size();k++) {
        int a = party[i][j];
        int b = party[i][k];
        graph[a].push_back(b);
        graph[b].push_back(a);
      }
    }
  }

  // bfs start with knower
  for(int i=0;i<a;i++) {
    bfs(knower[i] - 1); // num to idx
  }

  // 각 파티중 미방문된 노드로만 이루어진 파티의 개수를 센다.
  int answer = 0;
  for(int i=0;i<M;i++) {
    for(int j=0;j<party[i].size();j++) {
      // int node = graph[i][j];
      int node = party[i][j];
      if (visited[node]) break;
      if (j == party[i].size()-1) answer++;
    }
  }

  cout << answer << endl;
}

/*

문제 이해부터가 헬인데용...ㅠㅠ

주어진 것.
- 각 파티에 대한 참석명단
- "아는자" 정보

핵심사항.
- "아는자"와 지민이는 같은 파티에 참석할 수 없다.
- "아는자"와 같은 파티에 참여한 모든 사람들도 지민이와 같은 파티에 참석할 수 없다.

해결법.
- 그래프 탐색.
- "아는자"가 출발노드, 같은 파티에 참석하는 사람들끼리 간석으로 연결하는 그래프를 그린다.
- "아는자"를 출발노드로 그래프탐색을 수행.

- 각 파티정보를 순회, 그래프탐색결과 미방문된 노드로만 이루어진 파티만 카운팅한다.

*/

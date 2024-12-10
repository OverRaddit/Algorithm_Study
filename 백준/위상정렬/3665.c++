#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int adj[501][501] = {0};

void topol_sort(int n, vector<int>& inDegree, vector<int>& answer) {
  queue<int> q;
  bool isQuestion = false;
  answer.clear();

  for(int i=1;i<=inDegree.size()-1;i++) {
    if(inDegree[i] == 0) q.push(i);
  }

  while(!q.empty()) {
    if (q.size() > 1) { // 2개 이상이큐에 들어오면 정답배열이 여러경우가 될수있다.
      isQuestion = true;
      break;
    }

    int x = q.front();
    q.pop();
    answer.push_back(x);
    for(int i=1;i<=n;i++) {
      if (adj[x][i] == 0) continue;
      inDegree[i]--;
      if(inDegree[i] == 0)
        q.push(i);
    }
  }

  if (isQuestion)
    cout << "?\n";
  else if (answer.size() != n)
    cout << "IMPOSSIBLE\n";
  else {
    for(int i=0;i<answer.size();i++)
      cout << answer[i] << " ";
    cout << "\n";
  }
}

void Solve()
{
  memset(adj, 0, sizeof(adj));
  // INPUT
  int n,m;
  cin >> n;
  vector<int> order(n+1, 0);
  vector<int> inDegree(n+1, 0);
  vector<int> answer;

  for(int i=1;i<=n;i++) {
    cin >> order[i];
  }
  for(int i=1;i<=n;i++) {
    for(int j=i+1;j<=n;j++) {
      // order[i] -> order[i+1], 가중치 1생성
      int u = order[i];
      int v = order[j];
      inDegree[v]++;
      adj[u][v] = 1;
    }
  }
  cin >> m;
  for(int i=0;i<m;i++) {
    int a,b;
    cin >> a >> b; // 등수가아니라 팀번호임에 유의할것.

    // a->b간선이 있거나 b->a간선이 있을수밖에 없다.
    if (adj[a][b] == 1) {
      adj[a][b] = 0;
      inDegree[b]--;
      adj[b][a] = 1;
      inDegree[a]++;
    } else if (adj[b][a] == 1) {
      inDegree[a]--;
      adj[b][a] = 0;
      adj[a][b] = 1;
      inDegree[b]++;
    } else {}
  }

  topol_sort(n, inDegree, answer);
}

int main()
{
  int T;
  cin >> T;
  for(int i=0;i<T;i++) {
    Solve();
  }
}

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<vector<int> > v;

// int visited[100000] = {0};
int answer[100000] = {-1};

void bfs(int start) {
  queue<int> q;

  // visited[start] = true;
  answer[start] = true;
  q.push(start);
  while(!q.empty()) {
    int here = q.front();
    q.pop();
    for(int i=0;i<v[here].size();i++) {
      int there = v[here][i];

      // if(visited[there]) continue;
      // visited[there] = true;
      if(answer[there] != -1) continue;
      q.push(there);
      answer[there] = here;
    }
  }
}

int main()
{
  int N;
  cin >> N;
  v.resize(N);
  memset(answer, -1, sizeof(answer));
  for(int i=0;i<N-1;i++) {
    int a,b;
    cin >> a >> b; // num to idx
    v[a-1].push_back(b-1);
    v[b-1].push_back(a-1);
  }

  bfs(0);

  for(int i=1;i<N;i++) {
    cout << answer[i] + 1 << "\n"; // idx to num
  }
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int graph[1000][1000] = {0};
bool visited[1000][1000] = {0};
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
vector<pair<int,int> > walls;

void printGraph()
{
  // cout << "\n";
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      cout << graph[i][j] % 10;
    }
    cout << "\n";
  }
}

int bfs(int y, int x) {
  vector<pair<int,int> > walls;
  int ret = 0;
  queue<pair<int,int> > q;
  q.push(make_pair(y,x));
  visited[y][x] = true;

  while(!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();
    ret++;
    for(int i=0;i<4;i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if (ny>=N||nx>=M||ny<0||nx<0) continue; // 영역박
      if (visited[ny][nx]) continue;
      if (graph[ny][nx] >= 1) {
        walls.push_back(make_pair(ny,nx));
      }
      else if (graph[ny][nx] == 0) {
        q.push(make_pair(ny,nx));
      }
      visited[ny][nx] = true;
    }
  }

  for(int i=0;i<walls.size();i++) {
    graph[walls[i].first][walls[i].second] += ret;
    visited[walls[i].first][walls[i].second] = false;
  }
  return ret;
}

int main()
{
  // INPUT
  cin >> N >> M;
  string s;
  for(int i=0;i<N;i++) {
    cin >> s;
    for(int j=0;j<s.size();j++) {
      graph[i][j] = s[j] - '0';
      if(graph[i][j] == 1) walls.push_back(make_pair(i,j));
    }
  }

  // 빈칸에서 bfs를 수행하여 벽좌표에 bfs수행영역 칸 수만큼 더함.
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if (graph[i][j] == 0 && !visited[i][j]) {
        bfs(i, j);
        // printGraph();
      }
    }
  }
  printGraph();
}

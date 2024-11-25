#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int map[1000][1000] = {0};
int sum[1000][1000] = {0};
int answer[1000][1000] = {0};
bool visited[1000][1000] = {0};
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
vector<pair<int,int> > walls;

int bfs(int y, int x) {
  // bool visited[1000][1000] = {0};
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
      if (visited[ny][nx] || map[ny][nx] != 0) continue; // 방문 or 빈칸x
      q.push(make_pair(ny,nx));
      visited[ny][nx] = true;
    }
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
      map[i][j] = s[j] - '0';
      if(map[i][j] == 1) walls.push_back(make_pair(i,j));
    }
  }

  // [시간초과]모든 벽을 부수고 각 케이스마다 BFS수행
  // for(int i=0;i<walls.size();i++) {
  //   int wallY = walls[i].first;
  //   int wallX = walls[i].second;

  //   map[wallY][wallX] = 0;
  //   answer[wallY][wallX] = bfs(wallY, wallX) % 10;
  //   map[wallY][wallX] = 1;
  // }

  // 모든 좌표마다 BFS가 수행된

  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      bfs(i, j);
      // bfs 탐색영역의 개수만큼 각 좌표에 저장함.
    }
  }
  for(int i=0;i<walls.size();i++) {
    int wallY = walls[i].first;
    int wallX = walls[i].second;

    for(int j=0;j<4;j++) {
      int ny = wallY + dy[i];
      int nx = wallX + dx[i];

      if (ny>=N||nx>=M||ny<0||nx<0) continue; // 영역박
      answer[wallY][wallX] += sum[ny][nx];
    }
  }

  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      cout << answer[i][j];
    }
    cout << "\n";
  }
}

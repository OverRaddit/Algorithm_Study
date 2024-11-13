#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N,M;
int map[1000][1000] = {0};
int visited[1000][1000] = {0};

// 가로 세로로 이동
// 0은 벽, 1인 길, 2는 목표지점

// visited에서 시작지점부터 그래프탐색.
// 그래프탐색하며 타임스탬프를 visited에 기록.

// BFS함수
void BFS(int y, int x)
{
  // 방향 벡터 (상, 하, 좌, 우)
  int dy[] = {-1, 1, 0, 0};
  int dx[] = {0, 0, -1, 1};

  // 큐를 사용하여 BFS 구현
  queue<pair<int, int> > q;
  q.push(make_pair(y, x));
  visited[y][x] = 0; // 시작 지점의 타임스탬프를 0으로 설정

  while (!q.empty()) {
    int curY = q.front().first;
    int curX = q.front().second;
    q.pop();

    // 현재 위치에서 상하좌우로 이동
    for (int i = 0; i < 4; i++) {
      int nextY = curY + dy[i];
      int nextX = curX + dx[i];

      // 다음 위치가 범위 내에 있고, 방문하지 않았으며, 길이라면
      if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M && visited[nextY][nextX] == -1 && map[nextY][nextX] == 1) {
        visited[nextY][nextX] = visited[curY][curX] + 1; // 다음 위치의 타임스탬프를 현재 위치의 타임스탬프 + 1로 설정
        q.push(make_pair(nextY, nextX));
      }
    }
  }
}

int main()
{
  pair<int, int> start;

  memset(visited, -1, sizeof(visited));
  // INPUT
  cin >> N >> M;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      cin >> map[i][j];
      if (map[i][j] == 2) {
        map[i][j] = 1;
        start = make_pair(i, j);
      } else if (map[i][j] == 0) {
        visited[i][j] = 0;
      }
    }
  }


  BFS(start.first, start.second);

  // print visited
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      cout << visited[i][j] << " ";
    }
    cout << "\n";
  }
}

#include <iostream>
#include <queue>
using namespace std;

int N,M, pCnt=0;
int map[600][600] = {0};
bool visited[600][600] = {0};
char a;

void BFS(int y, int x)
{
  int dy[4] = {0, 0, 1, -1};
  int dx[4] = {1, -1, 0, 0};

  queue<pair<int, int> > q;
  q.push(make_pair(y, x));
  visited[y][x] = 1;

  while (!q.empty()) {
    int curY = q.front().first;
    int curX = q.front().second;
    q.pop();

    // 현재 위치에서 상하좌우로 이동
    for (int i = 0; i < 4; i++) {
      int ny = curY + dy[i];
      int nx = curX + dx[i];

      // 다음 위치가 범위 내에 있고, 방문하지 않았으며, 길이라면
      if (ny >= 0 && ny < N && nx >= 0 && nx < M && visited[ny][nx] == false && map[ny][nx] > 0) {
        visited[ny][nx] = true;
        if (map[ny][nx] == 2) pCnt++;
        q.push(make_pair(ny, nx));
      }
    }
  }
}

int main()
{
  pair<int,int> start;
  // INPUT
  cin >> N >> M;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      cin >> a;
      if (a == 'I') start = make_pair(i, j);
      else if (a == 'X') map[i][j] = 0;
      else if (a == 'O') map[i][j] = 1;
      else if (a == 'P') map[i][j] = 2;
    }
  }

  BFS(start.first, start.second);

  // print visited
  // for(int i=0;i<N;i++) {
  //   for(int j=0;j<M;j++) {
  //     cout << visited[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  if(pCnt == 0) cout << "TT" << endl;
  else cout << pCnt << endl;
}

#include <iostream>

using namespace std;

int R,C;
char map[20][20] = {0};
int answer = 0;
bool visited[26] = {0};

void dfs(int cnt, int y, int x) {
  answer = max(answer, cnt);

  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};

  // 상하좌우 접근
  for(int i=0;i<4;i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    // 맵을 벗어난 경우, 같은알파벳을 2번 지날경우 제외
    if (ny<0 || nx<0 || ny >= R || nx >= C ) continue;
    if (visited[map[ny][nx] - 'A']) continue;

    // 백트래킹
    visited[map[ny][nx] - 'A'] = true;
    dfs(cnt + 1, ny, nx);
    visited[map[ny][nx] - 'A'] = false;
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  cin >> R >> C;
  for(int i=0;i<R;i++) {
    for(int j=0;j<C;j++) {
      cin >> map[i][j];
    }
  }

  visited[map[0][0] - 'A'] = true;
  dfs(1, 0, 0);

  cout << answer << endl;
}

/*
그냥 브루트포스-백트래킹으로 구해볼까? dfs로 구현.
같은 알파벳은 두번지날수없고, 모든 알파벳은 26종류니까 dfs의 최대 depth는 26이하야.

21% 시간초과.
전체 맵 크기는 최대 400.
문자열을 붙이는 연산에서 시간을 줄여볼까?
생각해보니 dfs에서 문자열을 들고있을 필요가 전혀없네.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int N, answer=0;
int map[15][15] = {0};
bool visited[15][15] = {0};
vector<pair<int,int> > queens;

// void place_queen(int row, int col, int value) {
//   // 같은 행,열을 모두 방문처리
//   for(int i=0;i<N;i++) {
//     visited[row][i] = value;
//     visited[i][col] = value;
//   }

//   // 우측 대각선
//   for(int i=0;i<N;i++) {
//     for(int j=0;j<N;j++) {

//     }
//   }

//   // 좌측 대각선
// }

bool isAttacked(int r, int c) {
  for(int i=0;i<queens.size();i++) {
    int row = queens[i].first;
    int col = queens[i].second;

    if (row == r || col == c) return true;
    if (abs(row-r) == abs(col-c)) return true;
  }
  return false;
}

void dfs(int start) {
  if (start == N) {
    answer++;
    return;
  }

  for(int i=0;i<N;i++) {
    // 만약 starti 좌표가 퀸들의 공격범위라면 continue
    if (isAttacked(start, i)) continue;
    // 퀸 배치 visited[start][i]
    queens.push_back(make_pair(start, i));
    // 재귀
    dfs(start + 1);
    // 퀸 배치해제
    queens.pop_back();
  }
}

int main()
{
  cin >> N;

  dfs(0);
  cout << answer << endl;
}
/*

이거 어떻게 푸는거야;;
우선, 하나의 행에는 하나의 퀸만 올려놓을 수 있다.

퀸을 배치하면, 해당 퀸의 공격범위에 대해 표시해야함.

가로세로 공격범위는 쉽게 표현할 수 있는데..
대각선에 해당하는 공격범위를 어떻게 표시할지 잘 안떠오르네..
- row의 차이, col의 차이가 일치하면 대각선관계. 절댓값사용할것.

(1,2) (2,3) (3,4)

*/

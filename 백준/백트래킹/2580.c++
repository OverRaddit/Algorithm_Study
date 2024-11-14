#include <iostream>
#include <vector>
#define SIZE 9
using namespace std;

int map[SIZE][SIZE] = {0};
vector<pair<int,int> > blanks;

// blank좌표에 num을 기입할 수 있는지 판별한다.
bool validate(pair<int,int>& blank, int num) {
  // 같은 행렬에 중복된 숫자가 존재할 경우 false
  for(int i=0;i<SIZE;i++) {
    if (map[blank.first][i] == num) return false;
    if (map[i][blank.second] == num) return false;
  }

  // 3*3에 중복된 숫자가 존재할 경우 false
  int si = (blank.first / 3) * 3;
  int sj = (blank.second / 3) * 3;
  for(int i=si;i<si+3;i++) {
    for(int j=sj;j<sj+3;j++) {
      if (map[i][j] == num) return false;
    }
  }

  return true;
}

void dfs(int cnt) {
  if (cnt == blanks.size()) {
    for(int i=0;i<SIZE;i++) {
      for(int j=0;j<SIZE;j++) {
        cout << map[i][j] << " ";
      }
      cout << "\n";
    }
    exit(0);
    // return ;
  }

  pair<int,int> blank = blanks[cnt];
  // 각각의 빈칸들에 대해 백트래킹을 실시한다.
  for(int i=1;i<=9;i++) {
    if (!validate(blank, i)) continue;
    map[blank.first][blank.second] = i;
    dfs(cnt + 1);
    map[blank.first][blank.second] = -1;
  }
}

int main()
{
  // INPUT
  for(int i=0;i<SIZE;i++) {
    for(int j=0;j<SIZE;j++) {
      cin >> map[i][j];
      if (map[i][j] == 0)
        blanks.push_back(make_pair(i, j));
    }
  }
  // 이거 나중에 지우세요~~
  // 안지웠는데 통과되넹 ㅎㅎ;
  cout << "\n\n";

  //PROCESS
  dfs(0);
}

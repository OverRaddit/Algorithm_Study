#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>
#define MAX_SIZE 20
using namespace std;

int N, answer = INT_MAX;
int map[MAX_SIZE][MAX_SIZE] = {0};
bool selected[MAX_SIZE] = {0};

int getDiff() {
  int sp = 0;
  int lp = 0;
  int team_size = N/2;

  vector<int> start(team_size);
  vector<int> link(team_size);

  for(int i=0;i<N;i++) {
    if (selected[i]) start.push_back(i);
    else link.push_back(i);
  }

  for(int i=0;i<team_size;i++) {
    for(int j=i+1;j<team_size;j++) {
      int sx = start[i];
      int sy = start[j];
      int lx = link[i];
      int ly = link[j];
      sp += (map[sx][sy] + map[sy][sx]);
      lp += (map[lx][ly] + map[ly][lx]);
    }
  }
  return abs(sp-lp);
}

// 중복없이 오름차순으로 뽑아볼까.
void dfs(int cnt) {
  if (cnt == N/2) {
    int sp = 0;
    int lp = 0;
    answer = min(answer, getDiff());
    return;
  }

  for(int i=0;i<N;i++) {
    if (selected[i]) continue;
    selected[i] = true;
    dfs(cnt + 1);
    selected[i] = false;
  }
}

int main()
{
  // INPUT
  cin >> N;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin >> map[i][j];

  dfs(0);
  cout << answer << "\n";
}

/*
- N명중 절반 고르기. -> 백트래킹.
- 각 팀별 능력치 계산후 차이의 최솟값을 최신화.
*/

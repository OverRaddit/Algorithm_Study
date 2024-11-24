#include <iostream>
#include <string>
#include <vector>
#define SIZE 9
using namespace std;

vector<vector<int> > sudoku;
vector<pair<int,int> > zeros;

void print_board() {
  for(int i=0;i<9;i++) {
    for(int j=0;j<9;j++)
      cout << sudoku[i][j];
    cout << "\n";
  }
}

// blank좌표에 num을 기입할 수 있는지 판별한다.
bool validate(pair<int,int>& blank, int num) {
  // 같은 행렬에 중복된 숫자가 존재할 경우 false
  for(int i=0;i<SIZE;i++) {
    if (sudoku[blank.first][i] == num) return false;
    if (sudoku[i][blank.second] == num) return false;
  }

  // 3*3에 중복된 숫자가 존재할 경우 false
  int si = (blank.first / 3) * 3;
  int sj = (blank.second / 3) * 3;
  for(int i=si;i<si+3;i++) {
    for(int j=sj;j<sj+3;j++) {
      if (sudoku[i][j] == num) return false;
    }
  }

  return true;
}

void recursive(int n) {
  if (n == zeros.size()) {
    print_board();
    exit(0);
    return;
  }

  pair<int,int> blank = zeros[n];
  int y = zeros[n].first;
  int x = zeros[n].second;
  for(int i=1;i<=9;i++) {
    if(!validate(blank, i)) continue;
    sudoku[y][x] = i;
    recursive(n+1);
    sudoku[y][x] = 0;
  }
}

int main()
{
  sudoku.resize(9, vector<int>(9, 0));
  string s;
  for(int i=0;i<9;i++) {
    cin >> s;
    for(int j=0;j<s.size();j++) {
      sudoku[i][j] = s[j] - '0';
      if (sudoku[i][j] == 0) zeros.push_back(make_pair(i,j));
    }
  }

  // 백트래킹
  recursive(0);
}

#include <iostream>

using namespace std;

int N;
int arr[2] = {0}; // white, blue
int map[128][128] = {0};

bool check(int y, int x, int len)
{
  int color = map[y][x];
  for(int i=y;i<y+len;i++) {
    for(int j=x;j<x+len;j++) {
      if (map[i][j] != color) return false;
    }
  }
  return true;
}

void solve(int i, int j, int len)
{
  // cout << i << " " << j << " " << len << endl;
  int color = map[i][j];
  if (check(i, j, len)) {
    arr[color]++;
  } else {
    solve(i,j, len/2);
    solve(i,j+len/2, len/2);
    solve(i+len/2,j, len/2);
    solve(i+len/2,j+len/2, len/2);
  }
}

int main()
{
  cin >> N;
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      cin >> map[i][j];
    }
  }

  solve(0,0,N);

  cout << arr[0] << endl;
  cout << arr[1] << endl;
}

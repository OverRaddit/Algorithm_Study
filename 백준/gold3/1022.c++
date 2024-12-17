#include <iostream>
#include <vector>

using namespace std;

int r1,c1,r2,c2, W, H;
// vector<vector<int> > graph;
int map[5][50] = {0};

// (r,c)의 값에 num을 채운다.
void Fill(int r, int c, int num) {
  int row = r - r1;
  int col = c - c1;
  if (row < 0 || col < 0 || row >= H || col >= W) return;
  map[row][col] = num;
}

void Print() {
  for(int i=0;i<H;i++) {
    for(int j=0;j<W;j++) {
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  cin >> r1 >> c1 >> r2 >> c2;
  H = r2 - r1 + 1;
  W = c2 - c1 + 1;

  // ??? 어떻게 소용돌이 순서로 2차원배열에 접근할지 모르겠다.
  // for(int i=0;)
  int radius = 1;
  while (1) {

    Fill(0, 0, 1);
    Fill(0, 1, 2);
    Fill(-1, 1, 3);
    Fill(-1, 0, 4);
    Fill(-1, -1, 5);
    Fill(0, -1, 6);
    Fill(1, -1, 7);
    Fill(1, 0, 8);
    Fill(1, 1, 9);
    radius++;
  }

  Print();
}

/*

-3 -3 2 0인 map에서 0,0의 좌표는

x,y -> x+3, y+3
*/

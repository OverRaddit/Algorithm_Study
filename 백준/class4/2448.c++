#include <iostream>

# define MAX_ROW 3072
# define GETROW(x) 2 * x - 1
// # define MAX_COL MAX_ROW*2-1
using namespace std;

/*

소요시간 1시간.
N의 값에 따라 각 col의 길이를 도출하는 과정에서 오류가 있어 많이 헤맸다.
해당 값을 MAX_ROW, MAX_COL로 지정했다.
col을 구하는 공식 자체가 잘못되어 배열 크기선언, 공백값 초기화, 출력등등에서 문제가 있었다.
그러나 핵심적으로 col값만 잘 구했다면 틀리지 않았을텐데....
해당 공식을 define해두었다면 더 좋았을걸 한다.

*/

int N; // ~3072
char map[MAX_ROW][GETROW(MAX_ROW)] = {0};

void draw_min_triangle(int y, int x) {
    map[y][x] = '*';

    map[y+1][x-1] = '*';
    map[y+1][x+1] = '*';

    map[y+2][x-2] = '*';
    map[y+2][x-1] = '*';
    map[y+2][x] = '*';
    map[y+2][x+1] = '*';
    map[y+2][x+2] = '*';
}

// (y,x)를 삼각형 꼭대기 좌표로 하고 높이가 24인 삼각형을 map에 그린다.
void recursive(int N, int y, int x) {
  if (N == 3) {
    draw_min_triangle(y, x);
    return;
  }

  recursive(N/2, y, x);
  recursive(N/2, y + N/2, x - N/2);
  recursive(N/2, y + N/2, x + N/2);
}

int main()
{
  cin >> N;

  // INIT
  for(int i=0;i<N;i++) {
    // int width = 2*N - 1;
    int width = GETROW(N);
    for(int j=0;j<width;j++) {
      map[i][j] = ' ';
      // map[i][j] = '@';
    }
  }

  recursive(N, 0, N-1);

  // output
  for(int i=0;i<N;i++) {
    // int width = 2*N - 1;
    int width = GETROW(N);
    for(int j=0;j<width;j++) {
      cout << map[i][j];
    }
    cout << "\n";
  }
}

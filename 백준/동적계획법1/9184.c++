#include <iostream>
#include <string.h> // memset

using namespace std;

int dp[101][101][101] = {0};

int w(int a, int b, int c)
{
  if (a <= 0 || b <= 0 || c<= 0) return 1;
  if (dp[a][b][c] != -1) return dp[a][b][c];
  if (a>20 || b>20 || c>20) return dp[a][b][c] = w(20,20,20);
  else if (a < b && b < c)
    return dp[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
  else
    return dp[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1, b-1, c-1);
}

int main()
{
  int a,b,c;
  memset(dp, -1, sizeof(dp));

  while(1) {
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1) break;
    printf("w(%d, %d, %d) = %d\n", a,b,c, w(a,b,c));
  }

}
/*
- 30분 넘게품;;;;
- 종료조건일때도 출력을 해버리는 곳이 문제였는데 엉뚱한 곳만 고쳤다.
*/

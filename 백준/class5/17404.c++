#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int N,answer = INF;
int arr[1001][3] = {0};
int dp[1001][3] = {0};

int Solve(int startColor)
{
  int ret = INF;
  for(int i=1;i<N;i++) {
    int r = arr[i][0];
    int g = arr[i][1];
    int b = arr[i][2];
    dp[i+1][0] = r + min(dp[i][1], dp[i][2]);
    dp[i+1][1] = g + min(dp[i][0], dp[i][2]);
    dp[i+1][2] = b + min(dp[i][0], dp[i][1]);

  }
  // 각 값을 출력한다.
  // cout << dp[N][0] << " " << dp[N][1] << " " << dp[N][2] << endl;
  // 첫번째 집의 색은 마지막 집의 색과 달라야하므로, 정답후보에서 제외시킴.
  for(int i=0;i<3;i++) {
    if(i==startColor) continue;
    ret = min(ret, dp[N][i]);
  }

  return ret;
}

int main()
{
  // INPUT
  cin >> N;
  int r,g,b;
  for(int i=0;i<N;i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }

  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if (i == j)
        dp[1][j] = arr[0][j];
      else
        dp[1][j] = INF;
    }
    answer = min(answer, Solve(i));
  }
  cout << answer << endl;
}

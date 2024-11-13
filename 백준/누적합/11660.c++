#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> answer;
long long map[1024][1024] = {0};
long long dp[1024][1024] = {0};

// 인자는 모두 0-based index
// O(N)
int solve(int x1, int y1, int x2, int y2)
{
  int ret = 0; // long long?

  for(int x=x1;x<=x2;x++){
    if (y1 == 0)
      ret += dp[x][y2];
    else
      ret += dp[x][y2] - dp[x][y1-1];
  }

  // long long ret = dp[x2][y2];
  // if (x1 > 0) ret -= dp[x1-1][y2];
  // if (y1 > 0) ret -= dp[x2][y1-1];
  // if (x1 > 0 && y1 > 0) ret += dp[x1-1][y1-1];

  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int xx=0;xx<N;xx++) {
    for(int yy=0;yy<N;yy++) {
      cin >> map[xx][yy];
      if(xx==0 && yy==0) {
        dp[xx][yy] = map[xx][yy];
        continue;
      }
      dp[xx][yy] = dp[xx][yy-1] + map[xx][yy];
    }
  }
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //       cin >> map[i][j];
  //       dp[i][j] = map[i][j];
  //       if (i > 0) dp[i][j] += dp[i-1][j];
  //       if (j > 0) dp[i][j] += dp[i][j-1];
  //       if (i > 0 && j > 0) dp[i][j] -= dp[i-1][j-1];
  //   }
  // }

  for(int i=0;i<M;i++){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << solve(a-1,b-1,c-1,d-1) << "\n";
    // answer.push_back(solve(a-1,b-1,c-1,d-1));
  }

  // print dp
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //       cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for(int i=0;i<answer.size();i++)
    cout << answer[i] << "\n";

  return 0;
}

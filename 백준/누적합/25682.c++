#include <iostream>
#include <string>
using namespace std;

int N,M,K,answer = 10000000; // 2000 * 2000 / 2
int map[2000][2000] = {0};
int dp[2000][2000] = {0}; // dp[i][j] = (0,0)~(i,j)까지 블랙보드색칠비용

// i,j를 우측하단으로 하고 크기가 K인 체스판에서 체스판을 칠하는 최소값
int check(int i, int j)
{
  int ret = dp[i][j];

  if (i>K-1) ret -= dp[i-(K)][j];
  if (j>K-1) ret -= dp[i][j-(K)];
  if (i>K-1&&j>K-1) ret += dp[i-(K)][j-(K)];

  ret = min(ret, K*K - ret);

  return ret;
}

// i,j를 좌측상단으로 하고 크기가 K인 체스판에서 체스판을 칠하는 최소값
// int check2(int i, int j)
// {
//   int ret = dp[i+K][j+K] - dp[i][j+K] - dp[i+K][j] + dp[i][j];
//   ret = min(ret, K*K - ret);

//   return ret;
// }

int main()
{
  cin >> N >> M >> K;
  string s;
  for(int i=0;i<N;i++) {
    cin >> s;
    for(int j=0;j<M;j++) {
      int color = (s[j] == 'B') ? 0 : 1;
      int blackBoardColor = (i + j) % 2 == 0 ? 0 : 1;
      map[i][j] = color;
      if (color != blackBoardColor) dp[i][j] += 1;
      if (i>0) dp[i][j] += dp[i-1][j];
      if (j>0) dp[i][j] += dp[i][j-1];
      if (i>0&&j>0) dp[i][j] -= dp[i-1][j-1];
      // dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j];
    }
  }

  // print dp
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      cout << dp[i][j];
    }
    cout << "\n";
  }

  // 반복문에서 K * K보드로 잘라내는 모든 경우의 수를 체크한다.
  // v1 - i,j를 우측하단으로 함.
  for(int i=K-1;i<N;i++) {
    for(int j=K-1;j<M;j++) {
      answer = min(answer, check(i,j));
    }
  }

  // v2 - i,j를 좌측상단으로 함.
  // for(int i=0;i<=N-K;i++) {
  //   for(int j=0;j<=M-K;j++) {
  //     answer = min(answer, check2(i,j));
  //   }
  // }

  cout << answer << endl;

  return 0;
}

/*
N과 M은 최대 2000이다. 얼추 10^3이라고 생각하자.
check함수를 O(NM)번 수행한다. check함수가 상수시간이어야 통과가 될것같은데...

칠할 네모개수의 최솟값을 구하는 방법을 상수시간으로 통과시키려면...
누적합을 응용해야하는데 어떻게 연결지을지 잘 떠오르지 않는다.

혹시 체스판의 배치에 상관없이 블랙/화이트칸의 개수만으로 최솟값이 결정된다면?

알고있는 성질
화이트색칠비용 + 블랙색칠비용 = 체스판전체크기
즉, 한 색을 기준으로 비용을 알아낼 수 있으면 나머지 색의 비용도 알수있으므로 최솟값을 출력하는건 간단하다.
그렇다면 누적합을 이용해서 블랙색칠비용을 알아낼 방법을 떠올려보자.

dp를 이용해서 0,0~i,j까지의 사각형에 대해 블랙보드색칠비용을 도출했다.
이제 좌측상단이 0,0이 아닌경우도 적용할수 있다면 문제가 해결된다.... 어떡해야 하지?

정말 오랜만에 자력으로 해결한 골드문제!!!
*/

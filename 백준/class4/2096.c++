#include <iostream>
#include <queue>
#define COL_SIZE 3
using namespace std;

int map[100000][COL_SIZE] = {0};
int min_dp[COL_SIZE] = {0};
int max_dp[COL_SIZE] = {0};
int N;
pair<int,int> answer;

int main()
{
  // INPUT
  cin >> N;
  for(int i=0;i<N;i++)
    for(int j=0;j<COL_SIZE;j++)
      cin >> map[i][j];

  // 두번째 시도 - 통과
  max_dp[0] = min_dp[0] = map[0][0];
  max_dp[1] = min_dp[1] = map[0][1];
  max_dp[2] = min_dp[2] = map[0][2];
  int a,b,c;
  for(int i=1;i<N;i++) {
    a = max(min_dp[0], min_dp[1]) + map[i][0];
    b = max(max(min_dp[0], min_dp[1]), min_dp[2]) + map[i][1];
    c = max(min_dp[1], min_dp[2]) + map[i][2];
    min_dp[0] = a;
    min_dp[1] = b;
    min_dp[2] = c;

    a = min(max_dp[0], max_dp[1]) + map[i][0];
    b = min(min(max_dp[0], max_dp[1]), max_dp[2]) + map[i][1];
    c = min(max_dp[1], max_dp[2]) + map[i][2];
    max_dp[0] = a;
    max_dp[1] = b;
    max_dp[2] = c;
  }
  answer.first = max(max(min_dp[0], min_dp[1]), min_dp[2]);
  answer.second = min(min(max_dp[0], max_dp[1]), max_dp[2]);

  cout << answer.first << " " << answer.second << "\n";
}

#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX_N 3000
#define MOD 1000000007
// #define MAX_N 300000
using namespace std;

int N;
// int arr[300000] = {0};
long long arr[MAX_N] = {0};
long long dp[MAX_N] = {0};
long long answer = 0;

long long power(int a, int n) {
  long long ret = 1;
  for(int i=0;i<n;i++) {
    ret = ret * a;
    ret %= MOD;
  }
  return ret;
}

int main()
{
  cin >> N;
  for(int i=0;i<N;i++)
    cin >> arr[i];

  sort(arr, arr + N);

  // NC2 , 4,498,500
  for(int i=0;i<N;i++) {
    for(int j=i+1;j<N;j++) {
      // long long x = (arr[j] - arr[i]) %
      // i~j에서 나올 수 있는 조합의 수는 몇개?
      // 1~2 : 1
      // 1~3 : 2
      // 1~4 : 4
      // 1~5 : 8
      // answer += (arr[j] - arr[i]) * pow(2, j - i - 1) % MOD;
      answer += (arr[j] - arr[i]) * power(2, j - i - 1);
      answer %= MOD;
      cout << "answer += " << arr[j] << " - " << arr[i] << "\n";
      cout << "answer = " << answer << "\n";
    }
  }
  cout << answer % MOD << endl;
}
/*
dp[0][1] = 3
dp[0][2] = 12
dp[0][3] = 3

dp[1][2]

*/

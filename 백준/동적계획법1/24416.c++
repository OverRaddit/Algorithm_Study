#include <iostream>

using namespace std;

int N;
int recurCount = 0, dpCount = 0;
int dp[41] = {0};

int fib_recur(int n) {
  if (n == 1 || n == 2) {
    recurCount++;
    return 1;
  }
  return fib_recur(n-1) + fib_recur(n-2);
}

int fib_dp(int n) {
  if (n == 1 || n == 2) return 1;
  for(int i=3;i<=n;i++) {
    dp[i] = dp[i-1] + dp[i-2];
    dpCount++;
  }
  return dp[n];
}

int main()
{
  cin >> N;

  dp[1] = 1; dp[2] = 1;
  fib_recur(N);
  fib_dp(N);

  cout << recurCount << " " << dpCount << endl;
}
/*
7분.
*/

#include <iostream>
#include <vector>
// #include <cmath>
using namespace std;

int N,K,temp, sum=0;
vector<int> v;

int dp[100001] = {0};

int main()
{
  cin >> N >> K;
  for(int i=1;i<=N;i++){
    cin >> temp;
    v.push_back(temp);
    dp[i] = dp[i-1] + temp;
    // cout << "dp[" << i << "] = " << dp[i] << endl;
  }

  int answer = -100 * K; // 이 부분을 놓쳐서 한번더 제출함.
  for(int i=K;i<=N;i++){
    answer = max(answer, dp[i] - dp[i-K]);
    // cout << answer << endl;
  }
  cout << answer << endl;
}

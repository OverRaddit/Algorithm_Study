#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
int q;
vector<int> v;

int dp[200001][26] = {0};

int solve(char c, int l, int r)
{
  // l = 0이면 인덱싱불가능하므로 케이스추가
  if (l == 0)
    return dp[r][c-'a'];
  else
    return dp[r][c-'a'] - dp[l-1][c-'a'];
}

int main()
{
  cin >> s;

  dp[0][s[0]-'a']+=1;
  for(int i=1;i<s.size();i++){
    for(int j=0;j<26;j++) {
      dp[i][j] = dp[i-1][j];
    }
    dp[i][s[i]-'a']+=1;
  }

  cin >> q;
  for(int i=1;i<=q;i++){
    char c;
    int l,r;
    cin >> c >> l >> r;
    // cout << solve(c,l,r) << endl;
    v.push_back(solve(c,l,r));
  }
  for(int i=0;i<v.size();i++)
    cout << v[i] << "\n"; // endl쓰면 통과가 안됌.
}

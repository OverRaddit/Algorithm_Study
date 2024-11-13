#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
 // 0412
 // 1412 -> 첫트라이 왜틀림?
 // 1946
 // 3333 -> N==1 예외처리, sum타입, 배열크기 잘못설정..1모자람.
 // 3930 -> ll타입.
int N, C,answer = 0;
int arr[30] = {0};

void dfs(int s, int e, vector<ll>& v, ll sum) {
  if (s > e) {
    v.push_back(sum);
    return;
  }

  dfs(s+1, e, v, sum);
  dfs(s+1, e, v, sum + arr[s]);
}

int main()
{
  // INPUT
  cin >> N >> C;
  for(int i=0;i<N;i++)
    cin >> arr[i];

  vector<ll> x;
  vector<ll> y;

  dfs(0, N/2-1, x, 0);
  dfs(N/2, N-1, y, 0);

  sort(y.begin(), y.end());
  for(int i=0;i<x.size();i++) {
    ll rest = C - x[i];
    answer += upper_bound(y.begin(), y.end(), rest) - y.begin();
  }

  cout << answer << endl;
}

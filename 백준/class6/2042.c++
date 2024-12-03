#include <iostream>
#include <vector>
#include <map>
#define MAX_N 1000000
#define ll long long
using namespace std;

int N,M,K;
ll arr[MAX_N+1];
ll dp[MAX_N+1];

map<int, ll> layers;
vector<ll> answers;

int main()
{
  // INPUT
  cin >> N >> M >> K;
  for(int i=1;i<=N;i++) {
    cin >> arr[i];
    dp[i] = dp[i-1] + arr[i];
  }
  int a,b,c;
  for(int i=0;i<M+K;i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      layers[b] = c;
      // arr[b] = c;
    }
    else {
      ll layerOutput = 0;
      map<int,ll>::iterator start = layers.lower_bound(b);   // b 이상의 첫 번째 갱신값
      map<int,ll>::iterator end = layers.upper_bound(c);     // c 초과 이전까지의 갱신값

      for(map<int,ll>::iterator iter=start;iter!=end;iter++) {
        int layerRange = iter->first;
        ll layerValue = iter->second;
        // 레이어를 적용 - 업데이트하려는 곳의 값과 대입할 값의 차를 구한다.
        layerOutput += layerValue - arr[layerRange];
      }
      // cout << dp[c] - dp[b-1] + h << "\n";
      answers.push_back(dp[c] - dp[b-1] + layerOutput);
    }
  }
  for(int i=0;i<answers.size();i++) {
    cout << answers[i] << "\n";
  }
}

// #include <vector> // 구간 합 구하기
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// #define ll long long
// #define X 1048576

// ll n, m, k;
// ll atr[X]; // 원본
// ll dp[X], sc[10001][2]; // 0은 index b, 1은 그 인덱스에 업데이트할 값.

// void input()
// {
//     cin >> n >> m >> k;
//     for (int i = 1; i <= n; ++i)
//     {
//         cin >> atr[i];
//         dp[i] = dp[i - 1] + atr[i];
//     }
// }
// void mgsg()
// {
//   ll t = 0; // 레이어의 개수?
//   for (int i = 0; i < m + k; ++i)
//   {
//     ll a, b, c;
//     cin >> a >> b >> c;
//     if (a == 1)
//     {
//       for (int j = 0; j < 10001; ++j) // <- ?????
//       {
//         if (!sc[j][0] || !(sc[j][0] - b))
//         {
//           // j번째 레이어의 범위와 수정할값을 기록
//           sc[j][0] = b;
//           sc[j][1] = c;
//           t =  max(t, (long long)j);
//           break;
//         }
//       }
//     }
//     else
//     {
//         ll h = 0;
//         // 모든 레이어들중
//         for (int j = 0; j <= t; ++j)
//         {
//           // 구간이 일치하는 레이어들에 한하여,,
//           if (sc[j][0] >= b && c >= sc[j][0])
//           {
//             // 더한다. <- ??
//             h += sc[j][1] - atr[sc[j][0]];
//           }
//         }
//         // 원본 구간합에 유효한 레이어들의 총 결과물 h를 더한다.
//         cout << dp[c] - dp[b - 1] + h << "\n";
//     }
//   }
// }
// int main()
// {
//     ios::sync_with_stdio(0); cin.tie(0);
//     input();
//     mgsg();
//     return 0;
// }

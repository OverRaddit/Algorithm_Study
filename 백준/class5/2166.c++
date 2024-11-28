#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
typedef long long ll;
using namespace std;

int N; // 10^4
double answer = 0;
vector<pair<ll,ll> > v;

// v의 원소인 좌표들을 통해 면적을 계산한다.
double solve()
{
  ll sum=0;
  for(int i=0;i<v.size()-1;i++) {
    sum += v[i].first * v[i+1].second;
    sum -= v[i+1].first * v[i].second;
  }
  // return abs(sum) / 2; // 정수를 2로나누면서 값이 잘릴수있다.
  return fabs(static_cast<double>(sum)) / 2.0;
}

int main()
{
  // INPUT
  cin >> N;
  v.resize(N);
  for(int i=0;i<N;i++)
    cin >> v[i].first >> v[i].second;

  // 신발끈 공식을 위해 첫번째 좌표를 마지막에 다시 넣는다.
  v.push_back(v[0]);
  answer = solve();

  // OUTPUT
  cout << fixed << setprecision(1) << round(answer * 10) / 10 << endl;
}

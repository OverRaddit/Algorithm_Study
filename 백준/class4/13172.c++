#include <iostream>
#define MOD 1000000007
#define ll long long
using namespace std;

int M;
ll ans = 0;

// devide and conquer
ll power(ll x, ll y) {
  if (y == 1) return x;
  if (y%2 == 1) return x*power(x,y-1)%MOD;
  ll p = power(x,y/2);
  return p*p%MOD;
}

int main()
{
  // INPUT
  cin >> M;
  int n,s;
  for(int i=0;i<M;i++) {
    cin >> n >> s;
    ans += (s * power(n, MOD-2)) % MOD;
  }

  cout << ans % MOD << endl;
}

/*

풀긴했는데 복습해야할듯.
답을보니 너무 간단해...ㅋㅋ;;

*/

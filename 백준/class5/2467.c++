#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
using namespace std;
int N, answer = INT_MAX;
pair<int,int> p;
vector<int> v;

// 예전에 푼 투포인터문제랑 아예같은데...?

void solve()
{
  int left = 0,right = N-1;
  while(left < right) {
    int sum = v[left] + v[right];
    if (answer > abs(sum)) {
      answer = abs(sum);
      p = make_pair(v[left], v[right]);
    }
    if (sum < 0) {
      left++;
    } else if (sum > 0) {
      right--;
    } else {
      break;
    }
  }
}

int main()
{
  cin >> N;
  // INPUT
  v.resize(N);
  for(int i=0;i<N;i++)
    cin >> v[i];

  solve();

  cout << p.first << " " << p.second << "\n";
}

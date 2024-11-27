#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <algorithm>
using namespace std;
int N, answer = INT_MAX;
vector<int> trio;
vector<int> v;

void solve()
{
  int left = 0, mid, right = N-1;
  while(left < right) {
    mid = left + 1;
    int minSum;
    while(left < mid && mid < right) {
      int sum = v[left] + v[mid] + v[right];
      if (abs(answer) > abs(sum)) {
        answer = sum;
        trio = {v[left], v[mid], v[right]};
        minSum = sum;
      }
      mid++;
    }

    if (minSum < 0) {
      left++;
    } else if (minSum > 0) {
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

  sort(v.begin(), v.end());
  solve();
  // debug
  // for(int i=0;i<N;i++)
  //   cout << v[i] << " ";
  // cout << "\n";

  cout << trio[0] << " " << trio[1] << " " << trio[2] << "\n";
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,X, answer = 0;
vector<int> v;

int main()
{
  // INPUT
  //  (1 ≤ n ≤ 100,000, 1 ≤ x ≤ 2,000,000)
  cin >> N;
  int tmp;
  for(int i=0;i<N;i++){
    cin >> tmp;
    v.push_back(tmp);
  }
  cin >> X;

  sort(v.begin(), v.end());

  vector<int>::iterator left = v.begin();
  vector<int>::iterator right = v.end() - 1;
  while(1)
  {
    // cout << "left: " << *left << endl;
    // cout << "right: " << *right << endl;
    // cout << "answer: " << answer << endl;

    if (*left + *right < X) {
      left++;
    } else if(*left + *right > X){
      right--;
    } else {
      answer++;
      left++;
    }
    if (left >= right) break;
  }

  cout << answer << endl;
}


/*

1. 브루트 포스. O(N^2)으로 v를 순회한다.

-> N=10^5이므로 N^2 = 10^10으로 100억이 되어 시간초과될듯..

*/

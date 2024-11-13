#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N;
pair<int,int> answer = make_pair(0, 2000000000);
vector<int> v;

int main()
{
  cin >> N;
  int tmp;
  for(int i=0;i<N;i++) {
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());

  vector<int>::iterator left = v.begin();
  vector<int>::iterator right = v.end() - 1;
  while(1)
  {
    if (left >= right) break;

    int value = *left + *right;
    if (abs(answer.second + answer.first) > abs(value))
      answer = make_pair(*left, *right);

    if (value > 0)
      right--;
    else if (value < 0)
      left++;
    else
      break;
  }

  if (answer.first < answer.second)
    cout << answer.first << " " << answer.second << endl;
  else
    cout << answer.second << " " << answer.first << endl;
}
/*
1 2 3 4 99
*/

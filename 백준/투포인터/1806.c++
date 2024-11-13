#include <iostream>
#include <vector>
#define MAX_ANSWER 100001
using namespace std;

int N,S, answer = MAX_ANSWER;
vector<int> v;

// 이 알고리즘의 시간복잡도는???
void TwoPointer()
{
  // 1. 시간초과
  // for(int left=0;left<v.size();left++) {
  //   int right = left;
  //   int sum = 0;
  //   while(right < v.size()) {
  //     sum += v[right];
  //     if (sum < S)
  //       right++;
  //     else if (sum >= S) {
  //       answer = min(answer, right - left + 1);
  //       break;
  //     }
  //   }
  // }

  // 2.
  int sum = v[0], left = 0, right = 0;
  while(left <= right && right < v.size()){
    if (sum < S) {
      sum += v[++right];
    }
    else {
      answer = min(answer, right - left + 1);
      sum -= v[left];
      left++;
    }
  }

  // 정답케이스가 없다면 0을 출력한다.
  if (answer == MAX_ANSWER)
    answer = 0;
}

int main()
{
  int tmp;
  // INPUT
  cin >> N >> S;
  for(int i=0;i<N;i++){
    cin >> tmp;
    v.push_back(tmp);
  }

  TwoPointer();
  cout << answer << endl;
}

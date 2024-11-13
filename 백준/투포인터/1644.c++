/*
같은 방법 다른 표기 2가지 방법 시도!
문제는 N=1일때의 엣지케이스....!!
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, answer = 0;
vector<int> v;
int isPrime[4000000 + 1] = {0}; // isPrime[i]는 i가 소수라면 1

int main()
{
  cin >> N;

  // 엣지케이스
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }

  // 소수 배열을 생성한다.
  memset(isPrime, 1, sizeof(isPrime));
  for(int i=2;i<=N;i++) {
    for(int j=i*2;j<=N;j+=i) {
      isPrime[j] = 0;
    }
  }
  for(int i=2;i<=N;i++) {
    if (isPrime[i]) v.push_back(i);
  }

  // for(int i=0;i<v.size();i++)
  //   cout << v[i] << " ";
  // cout << endl;

  // 소수 배열을 앞에서부터 투포인터 전략을 사용하여 부분배열을 찾는다.
  // 1
  int left=0,right=0,sum=v[0];
  while(left <= right && right < v.size()) {
    if (sum < N) {
      sum += v[++right];
    } else if (sum > N) {
      sum -= v[left++];
    } else {
      answer++;
      sum -= v[left++];
    }
  }

  // 2
  // int left=0,right=0,sum=0;
  // while(left <= right && right <= v.size()) {
  //   if (sum < N) {
  //     sum += v[right++];
  //   } else if (sum > N) {
  //     sum -= v[left++];
  //   } else {
  //     answer++;
  //     sum -= v[left++];
  //   }
  // }

  cout << answer << endl;
}

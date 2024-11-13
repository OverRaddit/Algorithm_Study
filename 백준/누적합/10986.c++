#include <iostream>

using namespace std;

/*
신경쓸 것이 많았던 문제.
답을 도출하는 과정, 자료형선택등등...
*/

int N,M,temp;
int sum[1000001] = {0}; // 누적합모듈러 배열
int c[1001] = {0};
long answer = 0;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i=1;i<=N;i++){
    cin >> temp;
    sum[i] = (sum[i - 1] + temp % M) % M;
    if (sum[i] == 0) answer++;
  }

  // O(N^2)
  // for(int i=0;i<N;i++) {
  //   for(int j=i+1;j<=N;j++) {
  //     if ((sum[j] - sum[i]) % M == 0) answer++;
  //   }
  // }

  // O(NM)
  // for(int i=0;i<M;i++) {
  //   int count = 0;
  //   for(int j=1;j<=N;j++) {
  //     if (sum[j] == i) count++;
  //   }
  //   // cout << count << endl;
  //   // count C 2의 조합
  //   answer += ((count * (count-1)) / 2);

  //   // cout << answer << endl;
  // }

  // O(N)
  for(int i=1;i<=N;i++) {
    c[sum[i]]++;
  }
  for(int i=0;i<M;i++) {
    long tmp = c[i]; // ⭐️ 팩토리얼 연산시 오버플로우 발생가능.
    answer += ((tmp * (tmp-1)) / 2);
  }

  cout << answer << endl;

  return 0;
}

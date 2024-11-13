#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
int arr[1000000] = {0};
int F[1000000 + 1] = {0}; // 실수! 1 늘려야함.
vector<int> answer;

// 시간초과가 아닌 "틀렸습니다"가 나온다.. 원인은?
void brute_force() {
  // 브루트포스 - O(N^2)
  for(int i=0;i<N;i++) {
    int ngf = -1;
    // 우측(i+1 ~ N-1)에서
    for(int j=i+1;j<N;j++) {
      // 자신(arr[i])보다 빈도수가 높은 수
      if (F[arr[i]] < F[arr[j]]) {
        ngf = arr[j];
        break;
      }
    }
    answer.push_back(ngf);
  }
}

int main()
{
  // INPUT
  cin >> N; // 10^6
  for(int i=0;i<N;i++) {
    cin >> arr[i];
    F[arr[i]]++;
  }

  // PROCESS
  stack<int> big;
  stack<int> small;

  for(int i=N-1;i>=0;i--) {
    int ngf = -1;
    while(!big.empty()) {
      int top = big.top();
      if (F[arr[i]] < F[top]) {
        ngf = top;
        while(!small.empty()) {
          big.push(small.top());
          small.pop();
        }
        break;
      }
      else {
        small.push(top);
        big.pop();
      }
    }
    answer.push_back(ngf);

    big.push(arr[i]);
  }

  // answer 뒤집기.


  // OUTPUT
  for(int i=answer.size()-1;i>=0;i--) {
    cout << answer[i] << " ";
  }
  cout << endl;
}
/*
원본     1  1  2  3  4  2  1

F(1) = 3
F(2) = 2
F(3) = 1
F(4) = 1

NGF
  1 -1
  2 -1
  3 1
  4 2
  5 2
  6 1
  7 -1
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N,M;
vector<int> A;
vector<int> B;
vector<int> C;

deque<int> deq;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  cin >> N;
  for(int i=0;i<N;i++) {
    int temp;
    cin >> temp;
    A.push_back(temp);
  }
  for(int i=0;i<N;i++) {
    int temp;
    cin >> temp;
    B.push_back(temp);
  }
  cin >> M;
  for(int i=0;i<M;i++) {
    int temp;
    cin >> temp;
    C.push_back(temp);

    // 3 - 즉석으로 가능
  }

  // 1. 브루트포스
  // C의 각 원소에 대하여
  // for(int i=0;i<M;i++) {
  //   int input = C[i];
  //   int temp;

  //   // input을 큐스택에 입력
  //   for(int j=0;j<N;j++) {
  //     // queue라면 입력값과 기존값을 swap
  //     if (A[j] == 0) {
  //       temp = B[j];
  //       B[j] = input;
  //       input = temp;
  //     }
  //     // stack이라면 입력값을 그대로 통과하므로 진행.
  //   }
  //   cout << input << " ";
  // }
  // cout << endl;

  // 2 큐자료구조인 거만 담아서쓰기.
  // for(int i=0;i<N;i++) {
  //   if (A[i] == 0)
  //     deq.push_back(B[i]);
  // }
  // for(int i=0;i<M;i++) {
  //   deq.push_front(C[i]);
  //   cout << deq.back() << " ";
  //   deq.pop_back();
  // }
  // cout << endl;
}

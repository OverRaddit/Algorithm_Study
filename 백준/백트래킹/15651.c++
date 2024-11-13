#include <iostream>
#include <vector>

# define SIZE 7
using namespace std;

int N,M;
int arr[SIZE] = {0};

void print_arr() {
  for(int i=0;i<M;i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void solve(int cnt)
{
  if (cnt == M) {
    print_arr();
    return;
  }

  for(int i=1;i<=N;i++) {
    // 숫자 입력
    arr[cnt] = i;
    // 재귀
    solve(cnt+1);
    // 숫자 제거
    // arr[cnt] = -1;
  }
}

int main()
{
  cin >> N >> M;
  solve(0);
}

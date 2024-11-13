#include <iostream>
#include <vector>

# define SIZE 8
using namespace std;

int N,M;
int arr[SIZE] = {0};

void print_arr() {
  for(int i=0;i<M;i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

// 중복을 허용하면서 오름차순
// start는 데이터 시작범위를 나타내고, cnt는 재귀횟수를 나타냄.
void solve(int start, int cnt)
{
  if (cnt == M) {
    print_arr();
    return;
  }

  for(int i=start;i<=N;i++) {
    // 숫자 입력
    arr[cnt] = i;
    // 재귀
    solve(i, cnt+1);
    // 숫자 제거
    // arr[cnt] = -1;
  }
}

int main()
{
  cin >> N >> M;
  solve(1, 0);
}

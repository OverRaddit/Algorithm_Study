#include <iostream>
#include <vector>

# define SIZE 8
using namespace std;

int N,M;
int arr[SIZE] = {0};
bool visited[SIZE] = {0};

void print_arr() {
  for(int i=0;i<M;i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void solve(int start, int cnt)
{
  if (cnt == M) {
    print_arr();
    return;
  }

  for(int i=start;i<=N;i++) {
    if(visited[cnt]) continue;

    visited[cnt] = true;
    arr[cnt] = i;
    solve(i + 1, cnt+1);
    visited[cnt] = false;

  }
}

int main()
{
  cin >> N >> M;

  solve(1, 0);
}

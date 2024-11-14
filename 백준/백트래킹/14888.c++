#include <iostream>
#include <climits>
using namespace std;

int N, max_val = INT_MIN, min_val = INT_MAX;
int arr[11] = {0};
int oper[4] = {0};

int calculate(int a, int b, int oper) {
  switch (oper)
  {
  case 0:
    return a+b;
  case 1:
    return a-b;
  case 2:
    return a*b;
  case 3:
    return a/b;
  default:
    break;
  }
}

void dfs(int cnt, int sum) {
  if (cnt == N-1) {
    max_val = max(max_val, sum);
    min_val = min(min_val, sum);
    return;
  }

  for(int i=0;i<4;i++) {
    if (oper[i] < 1) continue;
    oper[i]--;
    dfs(cnt + 1, calculate(sum, arr[cnt+1], i));
    oper[i]++;
  }
}

int main()
{
  // INPUT
  cin >> N;
  for(int i=0;i<N;i++)
    cin >> arr[i];
  for(int i=0;i<4;i++)
    cin >> oper[i];

  dfs(0, arr[0]);

  // OUTPUT
  cout << max_val << "\n";
  cout << min_val << "\n";
}

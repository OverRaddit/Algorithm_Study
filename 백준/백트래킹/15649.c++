#include <iostream>
#include <vector>
using namespace std;

int N,M;
bool visited[9] = {0};
vector<int> v;

void print_vector() {
  for(int i=0;i<v.size();i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}

void solve(int cnt)
{
  if (cnt == M) {
    print_vector();
    return ;
  }

  for(int i=1;i<=N;i++) {
    if (!visited[i]) {
      visited[i] = true;
      v.push_back(i);
      solve(cnt + 1);
      v.pop_back();
      visited[i] = false;
    }
  }
}

int main()
{
  cin >> N >> M;

  solve(0);
}

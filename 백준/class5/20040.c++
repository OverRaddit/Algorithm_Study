#include <iostream>
#include <vector>

using namespace std;

int N,M;
pair<int,int> arr[1000000];

//union-find
int parent[500000] = {0};

int find_parent(int a) {
  if (parent[a] == a) return a;
  return parent[a] = find_parent(parent[a]);
}

// 이름을뭘로해야함?
void merge(int a, int b) {
  a = find_parent(a);
  b = find_parent(b);

  if (a < b) parent[b] = a;
  else parent[a] = b;
}

int main()
{
  std::ios_base::sync_with_stdio( false );
  std::cin.tie( NULL );
  std::cout.tie( NULL );
  // init
  for(int i=0;i<N;i++) parent[i] = i;
  // INPUT
  cin >> N >> M;
  for(int i=0;i<M;i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  int answer = -1;
  for(int i=0;i<M;i++) {
    int u = arr[i].first;
    int v = arr[i].second;
    if (find_parent(u) == find_parent(v)) {
      answer = i+1;
      break;
    }
    merge(u, v);
  }

  if(answer == -1)
    cout << 0 << "\n";
  else
    cout << answer << "\n";
}

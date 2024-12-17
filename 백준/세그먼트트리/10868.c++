#include <iostream>
#include <vector>
#define INF 9876543210

using namespace std;
typedef unsigned long long ull;

int N,M;
int nums[100000 + 1] = {0};
// ull tree[]
vector<ull> tree;
vector<ull> answer;

ull init(int s, int e, int node) {
  if (s == e) {
    return tree[node] = nums[s];
  }

  int mid = (s + e) >> 1;
  ull l = init(s, mid, node << 1);
  ull r = init(mid + 1, e, (node << 1) | 1);
  return tree[node] = min(l, r);
}

ull find_tree(int s, int e, int node, int left, int right) {
  ull l,r;

  // if (s < left || e > right) return INF;
  if (s > right || e < left) return INF;
  if (left <= s && e <= right) return tree[node];

  int mid = (s + e) >> 1;
  l = find_tree(s, mid, node << 1, left, right);
  r = find_tree(mid + 1, e, (node << 1) | 1, left, right);
  return min(l, r);
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> N >> M;
  tree.resize(4 * N, INF);
  for(int i=1;i<=N;i++) {
    cin >> nums[i];
  }
  init(1, N, 1);
  for(int i=0;i<M;i++) {
    int a,b;
    cin >> a >> b;
    // cout << find_tree(1, N, 1, a, b) << "\n";
    answer.push_back(find_tree(1, N, 1, a, b));
  }

  // output
  for(int i=0;i<answer.size();i++)
    cout << answer[i] << "\n";
}

#include <iostream>
#include <vector>
#define MOD 1000000007
typedef unsigned long long ull;
using namespace std;

int N,M,K;
vector<int> nums;
vector<ull> tree;

ull initTree(int s, int e, int node)
{
  // 리프노드인 경우
  if (s == e) {
    return tree[node] = nums[s];
  }

  // 리프노드가 아닌 경우
  int mid = (s+e) >> 1;
  int leftChild = node << 1;
  int rightChild = (node << 1) | 1;
  ull l = initTree(s, mid, leftChild);
  ull r = initTree(mid + 1, e, rightChild);
  return tree[node] = (l * r) % MOD;
}

// [left,..,start,..,end,..right]
// l,r은 고정하고 s는 증가, e는 감소하는 방향으로 이동한다.
ull find_tree(int s, int e, int node, int left, int right)
{
  // 구간불일치 -> [left,..,start,..,end,..right]
  // if (s < left || right < e) return 1;
  if (s > right || e < left) return 1;
  // 구간일치
  if (left <= s && e <= right) return tree[node];

  int mid = (s+e) >> 1;
  int leftChild = node << 1;
  int rightChild = (node << 1) | 1;
  ull l = find_tree(s, mid, leftChild, left, right);
  ull r = find_tree(mid + 1, e, rightChild, left, right);

  return (l * r) % MOD;
}

void update(int s, int e, int node, int target, int val)
{
  // ❌구간검색빼먹음 - target이 [s,e]를 벗어나면 종료한다.
  if (target < s || e < target) return;
  // leaf - target을 발견하면 update후 종료한다.
  if (s == e && s == target) {
    tree[node] = val;
    return;
  }

  int mid = (s+e) >> 1;
  int leftChild = node << 1;
  int rightChild = (node << 1) | 1;
  // ❌틀림 - 리프가 아닐때, 하위트리를 취합해 현노드를 업데이트한다.
  // if (s != target) {
  if (s != e) {
    update(s, mid, leftChild, target, val);
    update(mid + 1, e, rightChild, target, val);
  }
  tree[node] = (tree[leftChild] * tree[rightChild]) % MOD;
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> N >> M >> K;
  tree.resize(4 * N, 1);
  nums.resize(N + 1);
  for(int i=1;i<=N;i++) {
    cin >> nums[i];
  }
  initTree(1, N, 1);
  for(int i=0;i<M+K;i++) {
    int a,b,c;
    cin >> a >> b >> c;
    if (a == 1) {
      update(1, N, 1, b, c);
    } else {
      cout << find_tree(1, N, 1, b, c) << "\n";
    }
  }
  return 0;
}

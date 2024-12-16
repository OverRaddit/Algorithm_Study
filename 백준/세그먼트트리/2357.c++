#include <iostream>
#include <vector>
#define INF 9876543210 // INF 값 변경
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> Node;

int N,M,K;
vector<int> nums;
// 리프인경우 first,second에 값을 넣고 그외노드는 하위들값중 first가 max, second를 min으로 한다.
vector<Node> tree;

Node initTree(int s, int e, int node)
{
  // 리프노드인 경우
  if (s == e) {
    tree[node].second = tree[node].first = nums[s];
    return tree[node];
  }

  // 리프노드가 아닌 경우
  int mid = (s+e) >> 1;
  int leftChild = node << 1;
  int rightChild = (node << 1) | 1;
  Node l = initTree(s, mid, leftChild);
  Node r = initTree(mid + 1, e, rightChild);

  tree[node].first = max(l.first, r.first);
  tree[node].second = min(l.second, r.second);
  return tree[node];
}

Node find_tree(int s, int e, int node, int left, int right)
{
  if (s > right || e < left) return Node(0,INF);
  if (left <= s && e <= right) return tree[node];

  int mid = (s+e) >> 1;
  int leftChild = node << 1;
  int rightChild = (node << 1) | 1;
  Node l = find_tree(s, mid, leftChild, left, right);
  Node r = find_tree(mid + 1, e, rightChild, left, right);

  Node ret;
  ret.first = max(l.first, r.first);
  ret.second = min(l.second, r.second);

  return ret;
}

void update(int s, int e, int node, int target, int val)
{
  // ❌구간검색빼먹음 - target이 [s,e]를 벗어나면 종료한다.
  if (target < s || e < target) return;
  // leaf - target을 발견하면 update후 종료한다.
  if (s == e && s == target) {
    tree[node].first = tree[node].second = val;
    return;
  }

  int mid = (s+e) >> 1;
  int leftChild = node << 1;
  int rightChild = (node << 1) | 1;
  // ❌틀림 - 리프가 아닐때, 하위트리를 취합해 현노드를 업데이트한다.
  if (s != e) {
    update(s, mid, leftChild, target, val);
    update(mid + 1, e, rightChild, target, val);
  }
  // tree[node] = (tree[leftChild] * tree[rightChild]) % MOD;
  tree[node].first = max(tree[leftChild].first,tree[rightChild].first);
  tree[node].second = min(tree[leftChild].second,tree[rightChild].second);
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> N >> M;
  tree.resize(4 * N, Node(0, INF));
  nums.resize(N + 1);
  for(int i=1;i<=N;i++) {
    cin >> nums[i];
  }
  initTree(1, N, 1);
  for(int i=0;i<M;i++) {
    int a,b;
    cin >> a >> b;
    Node node = find_tree(1, N, 1, a, b);
    cout << node.second << " " << node.first << "\n";
  }
  return 0;
}

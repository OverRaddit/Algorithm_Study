#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef unsigned long long ull;
vector<int> nums;
vector<ull> tree;

// 데이터 nums[start-end]를 트리[node]에 대입한다.
ull init(int start, int end, int node)
{
  // 리프 노드인 경우 트리에 값 대입
  if (start == end)
    return tree[node] = nums[start];

  int mid = (start + end) >> 1;
  ull l = init(start, mid, node << 1);
  ull r = init(mid + 1, end, (node << 1) | 1);
  return (l * r) % MOD;
}

// 데이터 nums[start-end]범위의 트리[node]에서 target번째를 찾아 num으로 바꿈.
void update(int start, int end, int node, int target, int num)
{
  if (target < start || end < target)
    return;

  // if (start == end && tree[node] == target) {
  if (start == end && start == target) {
    tree[node] = num;
    return;
  }

  int mid = (start + end) >> 1;
  int leftChild = node << 1;
  int rightChild = (node << 1) | 1;

  if (start != end) {
    update(start, mid, leftChild, target, num);
    update(mid, end, rightChild, target, num);
  }

  tree[node] = (tree[leftChild] * tree[rightChild]) % MOD;
}

// find(1, N, 1, 3, 5)
ull find(int start, int end, int node, int left, int right)
{
    if (start > right || end < left)
      return 1;
    if (start >= left && end <= right) // [s,e]가 [l,r]내부에있나?
    {
      return tree[node];
    }
    int mid = (start + end) >> 1;
    int nextNode = node << 1;
    ull l = find(start, mid, nextNode, left, right);
    ull r = find(mid + 1, end, nextNode | 1, left, right);
    return (l * r) % 1000000007;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    nums = vector<int>(N + 1);
    tree = vector<ull>((N << 2), 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> nums[i];
    }
    init(1, N, 1);
    for (int i = 0; i < M + K; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(1, N, 1, b, c);
        }
        else
        {
            cout << find(1, N, 1, b, c) << "\n";
        }
    }
    return 0;
}

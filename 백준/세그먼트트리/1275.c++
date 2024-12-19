#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N,Q;
ll arr[100000 + 1] = {0};
vector<ll> tree;

ll init(int s, int e, int node) {
  if (s == e) {
    return tree[node] = arr[s];
  }

  int mid = (s + e) >> 1;
  ll l = init(s, mid, node << 1);
  ll r = init(mid + 1, e, (node << 1) | 1);
  return tree[node] = l + r;
}

// 혹시 update의 val인자가 int여서 오류가 났나? 아니네..
void update(int s, int e, int node, int target, int val) {
  if (s == e && s == target) {
    tree[node] = val;
    return;
  }

  int mid = (s + e) >> 1;
  int leftChild = node << 1;
  int rightChild = (node << 1) | 1;
  if (s != e) {
    // 이 작업을 안하면, 탐색범위가 아닌 곳까지 탐색한다.
    if (target <= mid)
      update(s, mid, leftChild, target, val);
    else
      update(mid + 1, e, rightChild, target, val);
  }
  tree[node] = tree[leftChild] + tree[rightChild];
}

ll query(int s, int e, int node, int left, int right) {
  // 구간검사
  if (s > right || e < left) return 0;
  if (left <= s && e <= right) return tree[node];

  int mid = (s + e) >> 1;
  ll l = query(s, mid, node << 1, left, right);
  ll r = query(mid + 1, e, (node << 1) | 1, left, right);
  return l+r;
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> N >> Q;
  tree.resize(4 * N, 0);
  for(int i=1;i<=N;i++) {
    cin >> arr[i];
  }
  init(1, N, 1);

  for(int i=0;i<Q;i++) {
    int x,y,a,b;
    cin >> x >> y >> a >> b; // x>y인 경우가있다고 노트에 표시됨.
    cout << query(1, N, 1, min(x,y), max(x,y)) << "\n";
    update(1, N, 1, a, b);
  }
}

/*

세그먼트 트리 알고리즘에 익숙해지기 위해 세그먼트트리 문제란것을 알고 푼 문제.
문제는 매우 간단하며 세그먼트트리를 알고있다면 바로 세그먼트트리가 떠오르는 문제이다.
바로 빡구현을 해보자. find파트의 구간종료검사코드를 틀리지않고 잘 짜보자구.

입력으로 들어오는 수의 값은 int범위.
INT_MAX * 10^5를 저장할수있는 자료형은? unsigned long long

한참을 fail을 받다가 문제의 입력배열의 범위에 음수가 포함된다는 것을 chatgpt가 말해줘서 파악했다.
지금까지 모든 세그먼트트리의 입력부는 양수여서 ull을 사용했는데,
문제의 입력조건을 무시하고 기존에 쓰던 자료형만 무지성으로 사용하다가 시간을 많이 날렸다.

이번 문제풀이의 교훈

1. 세그먼트트리는 밸런스트리가 아니다. 입력5개의 세그먼트에 대해. 모든리프노드의높이가 같지않음.
2. 세그먼트트리의 자료형을 잘 고려하자.
*/

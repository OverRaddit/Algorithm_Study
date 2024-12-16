#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef unsigned long long ull;
vector<int> nums;
vector<ull> tree;

ull init(int start, int end, int node)
{
    // 리프노드인 경우
    if (start == end)
        // 리프노드의 값은 nums의 값과 같다.
        return tree[node] = nums[start];

    int mid = (start + end) >> 1;
    int nextNode = node << 1;
    ull l = init(start, mid, nextNode);
    ull r = init(mid + 1, end, nextNode | 1);
    return tree[node] = (l * r) % MOD;
}

ull init2(int start, int end, int node)
{
    // 리프노드인 경우
    if (start == end)
        // 리프노드의 값은 nums의 값과 같다.
        return tree[node] = nums[start];

    int mid = (start + end) / 2;

    int nextNode = node << 1;
    ull l = init(start, mid, nextNode); // x2
    ull r = init(mid + 1, end, nextNode | 1); // (x|1)연산은 x의 최하위 비트를 1로 바꾸는 연산이다.
    return tree[node] = (l * r) % MOD;
}

// 1~N까지의 데이터이면서 node를 루트로 하는 트리에서 target번째 값을 num으로 바꾼다.
void update(int start, int end, int node, int target, int num)
{
    // target이 범위를 벗어난 경우
    if (start > target || end < target)
        return;

    // target값과 일치하는 리프노드를 찾은 경우
    if (start == target && end == target)
    {
        tree[node] = num;
        return;
    }

    // 서브 트리 탐색
    int mid = (start + end) >> 1;
    int nextNode = node << 1;
    if (start != end)
    {
        update(start, mid, nextNode, target, num);
        update(mid + 1, end, nextNode | 1, target, num);
    }

    // 부모노드의 값 수정
    tree[node] = (tree[nextNode] * tree[(nextNode | 1)]) % 1000000007;
}

// 1 N 1 b c
// 1~N까지의 데이터이면서 node를 루트로 하는 트리에서 left~right까지의 곱을 구한다.
// ex) 1 N 1 11 14
// ex) 1 4 2 11 14
// ex) 1 2 4 11 14
// ex) 3 4 5 11 14
// ex) 5 8 3 11 14
// ex) 5 6 6 11 14
// ex) 7 8 7 11 14
ull find(int start, int end, int node, int left, int right)
{
    // [start,end]가 쿼리범위 [left, right]와 겹치지 않는 경우
    // Ex) 쿼리범위 [4,6], 현재 세그먼트:[1,3]
    // 곱셈 연산에서 항등원을 반환함.
    if (start > right || end < left)
        return 1;
    // [start,end]가 쿼리범위 [left, right]와 완전히 겹치는 경우
    if (start >= left && end <= right)
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
    nums = vector<int>(N + 1); // 0번 인덱스는 사용하지 않는다.

    // 트리 자료구조의 크기는 데이터크기의 4배로 설정
    // 왜? 세그먼트 트리의 리프노드의 개수는 데이터의 개수와 같다.
    // 그렇다면 트리의 2^(K+1)개의 노드가 필요하다.
    // 그것와 N<<2가 무슨 관련이 있지?
    // 답:
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

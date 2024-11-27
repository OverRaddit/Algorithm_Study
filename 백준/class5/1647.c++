#include <iostream>
#include <vector>
#define MAX_N 100'000
#define MAX_M 1'000'000
#define MAX_C 1'000
using namespace std;

int N,M;
vector<pair<int,int> > graph[MAX_N];

int main()
{
  // INPUT
  // 임의의 두 집 사이에 경로가 항상 존재하는 입력만 주어진다.
  // 양방향 그래프
  cin >> N >> M;
  int A,B,C;
  for(int i=0;i<M;i++) {
    cin >> A >> B >> C;
    graph[A-1].push_back(make_pair(B-1, C));
    graph[B-1].push_back(make_pair(A-1, C));
  }

  // 어렵다;;
}

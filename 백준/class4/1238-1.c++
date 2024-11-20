#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define INTMAX 2147483647
#define MAX 1001

vector<pair<int, int>> Graph[2][MAX];  // 그래프를 순방향 및 역방향으로 나눠서 저장
int Dist[2][MAX];  // 각 방향에서의 최단 거리를 저장할 배열
int CostSave[MAX];

void Dijkstra(int Dir, int X)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, X});  // 시작 노드 X로부터의 거리가 0인 상태로 우선순위 큐에 추가
  Dist[Dir][X] = 0;  // 시작 노드 X의 최단 거리를 0으로 초기화

  while (!pq.empty())
  {
    int CurNode = pq.top().second;  // 현재 노드
    int CurCost = pq.top().first;   // 현재 노드까지의 최단 거리
    pq.pop();  // 최소 거리를 가진 노드를 우선순위 큐에서 제거

    // 이미 계산된 최단 거리보다 더 큰 거리로 왔다면 무시
    if (Dist[Dir][CurNode] < CurCost)
      continue;

    int Size = static_cast<int>(Graph[Dir][CurNode].size());
    for (int i = 0; i < Size; ++i)
    {
      int NextNode = Graph[Dir][CurNode][i].first;  // 다음 노드
      int NextCost = Graph[Dir][CurNode][i].second + CurCost;  // 다음 노드까지의 거리

      // 다음 노드까지의 거리가 더 짧다면 최단 거리 갱신하고 큐에 추가
      if (Dist[Dir][NextNode] > NextCost)
      {
        pq.push({NextCost, NextNode});
        Dist[Dir][NextNode] = NextCost;
      }
    }
  }
}

int main()
{
  int N, M, X;
  int answer = -1;

  cin >> N >> M >> X;

  // 그래프 연결
  for (int i = 0; i < M; ++i)
  {
    int A, B, Cost;
    cin >> A >> B >> Cost;
    Graph[0][A].push_back({B, Cost});  // 역방향 그래프 저장
    Graph[1][B].push_back({A, Cost});  // 순방향 그래프 저장
  }

  // 최단 거리 배열 초기화
  fill(Dist[0], Dist[1] + MAX, INTMAX);

  // 순방향 그래프에서 X로 가는 최단 거리 계산
  Dijkstra(1, X);

  // 역방향 그래프에서 X로 가는 최단 거리 계산
  Dijkstra(0, X);

  // 모든 정점에 대해 순방향과 역방향 최단 거리를 합쳐 최댓값 갱신
  for (int i = 1; i <= N; ++i)
  {
    answer = max(answer, Dist[0][i] + Dist[1][i]);
  }

  cout << answer;

  return 0;
}

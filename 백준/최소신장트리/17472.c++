#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int N,M, landCnt = 1;
int graph[10][10] = {0};
int adj[10][10] = {0}; // adj[a][b] = a섬에서 b섬까지의 다리길이
bool visited[10][10] = {0}, isImpossible = true;

// 인접배열 adj에 대하여 MST를 반환한다.

int prim() {
  int answer = 0;
  int minWeight[10] = {0}; // MST에 추가된 정점까지의 최소거리
  bool added[10] = {0}; // MST에 추가된 정점인지 여부
  int parent[10] = {0}; // MST에서의 부모노드

  for(int i=1;i<landCnt;i++) {
    minWeight[i] = INF;
    added[i] = false;
    parent[i] = -1;
  }

  // 시작섬은 1번섬이다.
  minWeight[1] = 0;
  parent[1] = 1;

  for(int i=1;i<landCnt;i++) {
    // 다음 추가할 정점 u를 찾는다.
    int u = -1;
    int min = INF;
    for(int j=1;j<landCnt;j++) {
      if(!added[j] && minWeight[j] < min) {
        u = j;
        min = minWeight[j]; // 이걸 빼먹어서 오래걸림.
      }
    }

    // parent[u], u를 MST에 추가한다.
    added[u] = true;
    answer += minWeight[u];

    // u에 인접한 정점들을 업데이트한다.
    for(int v=1;v<landCnt;v++) {
      if (adj[u][v] == INF) continue;
      if(!added[v] && adj[u][v] < minWeight[v]) {
        parent[v] = u;
        minWeight[v] = adj[u][v];
      }
    }
  }

  // 모든 정점이 연결되었는지 확인한다.
  // 이 부분을 놓쳐서 오래걸림.
  for(int i=1;i<landCnt;i++) {
    if (!added[i]) {
      return -1;
    }
  }

  return answer;
}

// graph[y][x]에서 가로or세로로 다리를 놓아본다.
void raycast(int y, int x, bool isVertical) {
  int dy[2] = {0,1};
  int dx[2] = {1,0};
  int len = 0;
  int u = graph[y][x],v; // raycast의 시작섬번호와 끝섬번호

  if(isVertical) {
    while(y < N) {
      y++;
      len++;
      // 같은섬을 만나면 끝
      if(graph[y][x] == u) return;
      // 다른섬을 만나면 끝
      if(graph[y][x] != 0) break;
    }
  } else {
    while(x < M) {
      x++;
      len++;
      // 같은섬을 만나면 끝
      if(graph[y][x] == u) return;
      // 다른섬을 만나면 끝
      if(graph[y][x] != 0) break;
    }
  }

  v = graph[y][x];
  if (len - 1 < 2) return; // 다리의 길이는 2 이상이어야 한다.
  // 양방향 그래프이므로 양쪽에 다리길이를 업데이트한다.
  adj[u][v] = min(adj[u][v], len - 1);
  adj[v][u] = min(adj[v][u], len - 1);
  isImpossible = false;

  // cout << "len = " << len << "\n";
}

void bfs(int y, int x, int landCnt) {
  int dy[4] = {0,0,1,-1};
  int dx[4] = {1,-1,0,0};
  queue<pair<int,int> > q;

  graph[y][x] = landCnt;
  q.push(make_pair(y,x));

  while(!q.empty()) {
    int sy = q.front().first;
    int sx = q.front().second;
    q.pop();

    for(int i=0;i<4;i++) {
      int ny = sy + dy[i];
      int nx = sx + dx[i];

      if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if(visited[ny][nx]) continue;
      if(graph[ny][nx] == 0) continue;

      visited[ny][nx] = true;
      graph[ny][nx] = landCnt;
      q.push(make_pair(ny,nx));
    }
  }
}

void input() {
  cin >> N >> M;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      cin >> graph[i][j];
    }
  }
}

int main()
{
  input();

  // 각섬에 번호를 매긴다.
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if (visited[i][j] || graph[i][j] == 0) continue;
      bfs(i,j, landCnt);
      landCnt++;
    }
  }

  // 다리를 놓아본다.
  for(int i=1;i<=landCnt;i++)
    for(int j=1;j<=landCnt;j++)
      adj[i][j] = INF;

  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if (graph[i][j] == 0) continue;
      raycast(i,j,true);
      raycast(i,j,false);
    }
  }

  if (isImpossible) {
    cout << "-1\n";
    return 0;
  }

  // // DEBUG
  // cout << "\nGRAPH\n";
  // for(int i=0;i<N;i++) {
  //   for(int j=0;j<M;j++) {
  //     cout << graph[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  // cout << "\nADJ\n";
  // for(int i=1;i<landCnt;i++) {
  //   for(int j=1;j<landCnt;j++) {
  //     if (adj[i][j] == INF) cout << "0 ";
  //     else
  //       cout << adj[i][j] << " ";
  //     // cout << adj[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  cout << prim() << endl;
}

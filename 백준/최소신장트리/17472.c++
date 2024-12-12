#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int N,M, landCnt = 1;
int graph[10][10] = {0};
int adj[10][10] = {0}; // adj[a][b] = a섬에서 b섬까지의 다리길이
bool visited[10][10] = {0};

// 인접배열 adj에 대하여 MST를 반환한다.
int prim() {
  int answer = 0;
  int dist[10] = {0};
  bool selected[10] = {0};
  int parent[10] = {0};

  for(int i=1;i<=landCnt;i++) {
    dist[i] = INF;
    selected[i] = false;
    parent[i] = -1;
  }

  // 시작섬은 1번섬이다.
  dist[1] = parent[1] = 0;

  for(int i=1;i<=landCnt;i++) {
    // 다음 추가할 정점 u를 찾는다.
    int u = -1;
    int min = INF;
    for(int j=1;j<=landCnt;j++) {
      if(!selected[j] && dist[j] < min) {
        u = j;
        // min = dist[j];
      }
    }

    // parent[u], u를 MST에 추가한다.
    selected[u] = true;
    // answer += dist[u];

    // u에 인접한 정점들을 업데이트한다.
    for(int v=1;v<=landCnt;v++) {
      if(adj[u][v] != INF && !selected[v] && adj[u][v] < dist[v]) {
        parent[v] = u;
        dist[v] = adj[u][v];
      }
    }
  }

  for(int i=1;i<=landCnt;i++) {
    if (dist[i] == INF) continue;
    answer += dist[i];
    cout << "dist[" << i << "] = " << dist[i] << "\n";
    // cout << dist[i] << " ";
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
  if (len < 2) return; // 다리의 길이는 2 이상이어야 한다.
  // 양방향 그래프이므로 양쪽에 다리길이를 업데이트한다.
  adj[u][v] = min(adj[u][v], len);
  adj[v][u] = min(adj[v][u], len);

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

  // DEBUG
  cout << "\nGRAPH\n";
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      cout << graph[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\nADJ\n";
  for(int i=1;i<=landCnt;i++) {
    for(int j=1;j<=landCnt;j++) {
      cout << adj[i][j] << " ";
    }
    cout << "\n";
  }

  cout << prim() << endl;

}

/*

조건이 많고 까다롭다...

1. 모든 섬들간의 다리를 알아낸다.

- 1) 모든지점에서 bfs수행하여 섬들마다 별도의 값을 매긴다.
- 2) 모든지점에서 가로or세로방향으로 bfs수행하여 다리를 알아낸다.
- 2) 이때 다리의 길이는 min값으로 업데이트한다.

2. 크루스칼 알고리즘을 적용한다.

-> 크루스칼 알고리즘은 인접리스트일때 효율적인데 지금은 그래프가 리스트형태가 아님.
-> 차라리 프림 알고리즘을 쓰는 것이 좋을 듯 함.

3. 그래프크기가 100인것으로 보아 브루트포스를 돌리는듯.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define BLOCKNUM 3
using namespace std;

int N,M,answer=-1;
int map[8][8] = {0}; // 아마 브루트포스
bool visited[8][8] = {0};
vector<pair<int,int> > virus;

void bfs(int y, int x) {
  int dy[4] = {0,0,-1,1};
  int dx[4] = {1,-1,0,0};
  queue<pair<int,int> > q;
  q.push(make_pair(y,x));
  visited[y][x] = true;

  while(!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for(int i=0;i<4;i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if (ny>=N||nx>=M||ny<0||nx<0) continue; // 영역박
      if (visited[ny][nx] || map[ny][nx] != 0) continue; // 방문 or 빈칸x
      q.push(make_pair(ny,nx));
      visited[ny][nx] = true;
    }
  }
}

int getSafetyArea() {
  // 각 virus들에 대하여 그래프탐색을 수행한다.
  memset(visited, 0, sizeof(visited));
  for(int i=0;i<virus.size();i++) {
    bfs(virus[i].first, virus[i].second);
  }

  // 안전영역의 크기를 계산하고 정답을 update한다.
  int count = 0;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if(map[i][j] == 0 && !visited[i][j]) count++;
    }
  }

  return count;
}

void recursive(int n, int y, int x) {
  if (n == BLOCKNUM) {
    int count = getSafetyArea();
    answer = max(answer, count);
    return;
  }

  for(int i=y;i<N;i++) {
    for(int j=(i == y ? x : 0);j<M;j++) {
      if (map[i][j] == 0) {
        map[i][j] = 1;
        recursive(n + 1, i, j+1);
        map[i][j] = 0;
      }
    }
  }
}

// 백트래킹으로 전체경우의 수를 구하는 대상이 2차원 배열의 좌표일때, 1차원배열로 생각해두는게 간단하다.
void recursive2(int n, int startIndex) {
  if (n == BLOCKNUM) {
    int count = getSafetyArea();
    answer = max(answer, count);
    return;
  }

  for(int i=startIndex;i<N*M;i++) {
    int row = i / M;
    int col = i % M;
    if (map[row][col] == 0) {
      map[row][col] = 1;
      recursive2(n + 1, i);
      map[row][col] = 0;
    }
  }
}

int main()
{
  // INPUT
  cin >> N >> M;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      cin >> map[i][j]; // 0빈칸, 1벽, 2바이러스
      if (map[i][j] == 2) virus.push_back(make_pair(i,j));
    }
  }

  // 브루트포스로 3개의 벽을 세우는 모든 경우의 수를 구한다.
  recursive2(0,0);

  cout << answer << endl;
}
/*

4 6
0 0 0 0 1 0
1 0 0 1 0 2
1 1 1 0 0 2
0 0 0 1 0 2

*/

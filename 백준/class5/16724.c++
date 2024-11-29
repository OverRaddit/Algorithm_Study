#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N,M;
int map[1000][1000] = {0};
bool visited[1000][1000] = {0};
// UDLR
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

bool isReverseDir(int a, int b) {
  if (a == 0)
    return b==1;
  else if (a == 1)
    return b==0;
  else if (a== 2)
    return b==3;
  else if (a== 3)
    return b==2;
  else return false;
}

void printMap() {
  cout << "\n";
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      // cout << map[i][j] << " ";
      cout << visited[i][j] << " ";
    }
    cout << "\n";
  }
}

int bfs(int y, int x) {
  int ret = 0;
  queue<pair<int,int> > q;
  q.push(make_pair(y,x));

  while(!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    visited[cy][cx] = true;
    q.pop();
    for(int i=0;i<4;i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if (ny<0||nx<0||ny>=N||nx>=M) continue;
      if (visited[ny][nx]) continue;
      int dir = map[cy][cx];
      int dir2 = map[ny][nx];
      if (i == dir || isReverseDir(i,dir2)) {
        q.push(make_pair(ny,nx));
        visited[ny][nx] = true;
        ret++;
      }
    }
  }
  return ret;
}

int main()
{
  // INPUT
  cin >> N >> M;
  string s;
  for(int i=0;i<N;i++) {
    cin >> s;
    for(int j=0;j<s.size();j++) {
      if (s[j] == 'U'){
        map[i][j] = 0;
      }
      else if (s[j] == 'D'){
        map[i][j] = 1;
      }
      else if (s[j] == 'L'){
        map[i][j] = 2;
      }
      else if (s[j] == 'R'){
        map[i][j] = 3;
      }
    }
  }

  int answer = 0;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if (visited[i][j]) continue;
      int cnt = bfs(i,j);
      if (cnt > 0) answer++;
      // cout << cnt << "\n";
      // printMap();
    }
  }
  cout << answer << endl;
}

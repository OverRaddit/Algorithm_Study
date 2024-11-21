#include <stdio.h>
#include <queue>
using namespace std;

int arr[105][105];
int xx[4]={0,0,-1,1};
int yy[4]={1,-1,0,0};
int n,m;
int ans;
queue<pair<int,int> > q;

void dfs(int x,int y){
  if(arr[x][y]==0)
    arr[x][y]=-1;
  else return;

  for(int i=0;i<4;i++){
    int X = x+xx[i];
    int Y = y+yy[i];

    if(X>=1 && X<=n && Y>=1 && Y<=m)
      dfs(X,Y);
  }

  return;
}

int main(){
  scanf("%d %d",&n,&m);

  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      scanf("%d",&arr[i][j]);

  dfs(1,1);
  while(true){
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        if(arr[i][j]==1){
          int cnt = 0;
          for(int k=0;k<4;k++){
            int X = i+xx[k];
            int Y = j+yy[k];

            if(arr[X][Y]==-1) cnt++;
          }

          if(cnt>=2)
            q.push(make_pair(i,j));
        }

    if(q.empty()) break;

    while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      arr[x][y] = -1;

      for(int i=0;i<4;i++){
        int X = x+xx[i];
        int Y = y+yy[i];

        if(arr[X][Y]==0)
          dfs(X,Y);
      }
    }

    ans++;
  }

  printf("%d",ans);

  return 0;
}

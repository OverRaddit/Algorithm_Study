#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, answer = -1;
// vector<vector<int> > v;
vector<pair<int,int> > v[100001];
// int weight[100000][100000] = {0};
bool visited[10000] = {0};

void dfs(int start, int sum) {
  answer = max(answer, sum);
  visited[start] = true;

  for(int i=0;i<v[start].size();i++) {
    int there = v[start][i].first;
    int weight = v[start][i].second;
    if(visited[there]) continue;
    dfs(there, sum + weight);
  }
}

int main()
{
  cin >> N;
  for(int i=0;i<N;i++) {
    int num, len;
    cin >> num;
    while(1) { // num to idx
      cin >> num;
      if (num == -1) break;
      cin >> len;
      v[i].push_back(make_pair(num-1, len));
    }
  }

  for(int i=0;i<N;i++) {
    memset(visited, 0, sizeof(visited));
    dfs(i, 0);
  }

  cout << answer << endl;
}

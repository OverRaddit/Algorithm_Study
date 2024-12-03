#include <iostream>
#include <vector>

using namespace std;

int T;
vector<vector<int> > graph;

int kruskal(int src) {

}

void Solve()
{
  // INPUT
  int N,M,a,b;
  cin >> N >> M;
  graph.resize(N);
  for(int i=0;i<M;i++) {
    cin >> a >> b;
    graph[a-1].push_back(b-1);
    graph[b-1].push_back(a-1);
  }
}

int main()
{
  cin >> T;
  for(int i=0;i<T;i++) {
    Solve();
  }
}

/*
크루스칼 알고리즘을 써봅시다.
*/

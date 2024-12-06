#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m,n;
int parents[200000] = {0};
vector<pair<int, pair<int, int> > > edges;

int find_parent(int a) {
  if (parents[a] == a) return a;
  return parents[a] = find_parent(parents[a]);
}

void merge(int a, int b) {
  a = find_parent(a);
  b = find_parent(b);
  if (a < b) parents[b] = a;
  else parents[a] = b;
}

// 최소신장트리를 구하자. 크루스칼알고리즘.
void Solve(int sum) {
  int answer = 0;
  sort(edges.begin(), edges.end());
  for(int i=0;i<edges.size();i++) {
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    int cost = edges[i].first;
    if (find_parent(u) == find_parent(v)) continue;
    merge(u,v);
    answer += cost;
  }
  cout << sum - answer << "\n";
}

int main()
{
  while(1) {
    cin >> m >> n;
    if (m == 0 && n == 0) break;
    for(int i=0;i<n;i++) parents[i] = i;
    edges.clear();
    int sum = 0;
    for(int i=0;i<n;i++) {
      int x,y,z;
      cin >> x >> y >> z;
      sum += z;
      edges.push_back(make_pair(z, make_pair(x,y)));
    }
    Solve(sum);
  }

  return 0;
}

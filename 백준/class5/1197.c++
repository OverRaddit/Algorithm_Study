#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V,E;
vector<pair<int,int> > graph[10000];

/*
- DisjointSet을 만드는데 시간이 은근 걸림. 강의한번 보고만든거라 오류가 있었음.
- 크루스칼 알고리즘이 DisjointSet을 제외하면 간결해서 활용도가 높을듯함.
*/

struct DisjointSet {
  vector<int> parents;

  DisjointSet(int v) : parents(vector<int>(v)) {
    for(int i=0;i<v;i++) parents[i]=i;
  }
  int find(int u) {
    if (parents[u] == u) return u;
    else return parents[u] = find(parents[u]);
  }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (u<v) parents[v] = u;
    else parents[u] = v;
  }
};

int kruskal(vector<pair<int,int> >& selected) {
  int totalWeight = 0;
  selected.clear();
  vector<pair<int,pair<int,int> > > edges;
  for(int u=0;u<V;u++) {
    for(int i=0;i<graph[u].size();i++) {
      int v = graph[u][i].first;
      int w = graph[u][i].second;
      edges.push_back(make_pair(w,make_pair(u,v)));
    }
  }
  sort(edges.begin(), edges.end());
  DisjointSet sets(V);
  for(int i=0;i<edges.size();i++) {
    int cost = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    if (sets.find(u) == sets.find(v)) continue;
    sets.merge(u,v);
    selected.push_back(make_pair(u,v));
    totalWeight += cost;
  }

  return totalWeight;
}

int main()
{
  // INPUT
  cin >> V >> E;
  int u,v,w;
  for(int i=0;i<E;i++) {
    cin >> u >> v >> w;
    graph[u-1].push_back(make_pair(v-1, w));
    graph[v-1].push_back(make_pair(u-1, w));
  }

  vector<pair<int,int> > selected;
  int answer = 0;
  answer = kruskal(selected);
  cout << answer << "\n";
}

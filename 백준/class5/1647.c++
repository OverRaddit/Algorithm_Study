#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<pair<int,pair<int,int> > > edges;

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

int kruskal(int& maxWeight) {
  maxWeight = 0;
  int totalWeight = 0;
  DisjointSet sets(N);
  for(int i=0;i<edges.size();i++) {
    int cost = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    if (sets.find(u) == sets.find(v)) continue;
    sets.merge(u,v);
    maxWeight = max(maxWeight, cost);
    totalWeight += cost;
  }

  return totalWeight;
}

int main()
{
  // INPUT
  cin >> N >> M;
  int A,B,C;
  for(int i=0;i<M;i++) {
    cin >> A >> B >> C;
    edges.push_back(make_pair(C,make_pair(A-1,B-1)));
  }
  sort(edges.begin(), edges.end());

  // MST에 포함된 가장큰 간선을 삭제.
  int maxWeight;
  int answer = kruskal(maxWeight);
  cout << answer - maxWeight << "\n";
}

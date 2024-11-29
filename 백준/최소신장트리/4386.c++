#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<pair<double,double> > nodes;
vector<pair<double,pair<int,int> > > edges;

int N;
int parent[110]; // ?

double getDist(pair<double,double> a, pair<double,double> b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int Find_parent(int A) {
  if (A == parent[A]) return A;
  return parent[A] = Find_parent(parent[A]);
}

void Union(int A, int B){
  A = Find_parent(A);
  B = Find_parent(B);

  if (A < B)
    parent[B] = A;
  else
    parent[A] = B;
}

double kruskal() {
  double totalWeight = 0;

  for (int i = 0; i < N; i++) parent[i] = i;
  for(int i=0;i<edges.size();i++) {
    double cost = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    if (Find_parent(u) == Find_parent(v)) continue;
    Union(u,v);
    totalWeight += cost;
  }

  return totalWeight;
}

int main()
{
  // INPUT
  double a,b;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> a >> b;
    nodes.push_back(make_pair(100 * a, 100 * b));
  }

  // 각 좌표별 가중치 생성하여 간선배열만들기.
  for(int i=0;i<nodes.size()-1;i++) {
    for(int j=i+1;j<nodes.size();j++) {
      double dist = getDist(nodes[i], nodes[j]);
      edges.push_back(make_pair(dist, make_pair(i, j)));
    }
  }
  sort(edges.begin(), edges.end());

  // mst 알고리즘
  cout << kruskal() / 100 << "\n";
}

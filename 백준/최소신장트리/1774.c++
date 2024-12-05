#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<int,int> > gods;
vector<pair<double,pair<int,int> > > edges;

int N,M;
int parents[1001] = {0};
double answer = 0;
/*
우주신을 노드로 하는 그래프에서 최소신장트리를 구한다.
이때 무조건 연결되어야하는 특정 간선이 존재한다.
*/

// 이걸 잘못구현해서 한참걸렸다. 잘못구현한것도 남겨둡니다.
double getDist(pair<int,int> a, pair<int,int> b) {
  // double dist = 0;
  // dist += (a.first - b.first) * (a.first - b.first);
  // dist += (a.second - b.second) * (a.second - b.second);
  // dist = sqrt(dist);
  // return dist;
  double x_dist = pow(a.first - b.first, 2);
  double y_dist = pow(a.second - b.second, 2);

  return sqrt(x_dist + y_dist);
}

int find_parents(int a) {
  if (parents[a] == a) return parents[a];
  return find_parents(parents[a]);
}

void merge(int a, int b) {
  a = find_parents(a);
  b = find_parents(b);
  if (a < b) parents[b] = a;
  else parents[a] = b;
}

int main()
{
  cin >> N >> M;
  for(int i=0;i<N;i++) parents[i] = i;
  int a,b;
  for(int i=0;i<N;i++) {
    cin >> a >> b;
    gods.push_back(make_pair(a,b));
  }
  for(int i=0;i<M;i++) {
    cin >> a >> b;
    merge(a-1,b-1);
  }

  // init
  for(int i=0;i<N-1;i++) {
    for(int j=i+1;j<N;j++) {
      double dist = getDist(gods[i], gods[j]);
      edges.push_back(make_pair(dist, make_pair(i, j)));
    }
  }

  sort(edges.begin(), edges.end());
  for(int i=0;i<edges.size();i++) {
    double dist = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    if (find_parents(u) == find_parents(v)) continue;
    merge(u,v);
    answer += dist;
  }
  cout << fixed;
  cout.precision(2);
  cout << round(100 * answer) / 100 << "\n";
}

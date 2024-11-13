#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

typedef pair<int,int> pii;
int N,M;
vector<pii> houses;
vector<pii> chickens;
int result = INT_MAX;

int getChickenDistance(vector<pii>& selected) {
  int totalDistance = 0;
  for(int i=0;i<houses.size();i++) {
    pii house = houses[i];
    int hr = house.first;
    int hc = house.second;
    int minDistance = INT_MAX;

    for(int j=0;j<selected.size();j++) {
      pii chicken = selected[j];
      int cr = chicken.first;
      int cc = chicken.second;
      int distance = abs(hr-cr) + abs(hc-cc);
      minDistance = min(minDistance, distance);
    }
    totalDistance += minDistance;
  }
  return totalDistance;
}

// 백트래킹 - 치킨집 선택 조합을 구한다. -> 백트래킹 기법이 잘 기억나지 않는구만...
void chooseChickens(int start, vector<pii>& selected) {
  if (selected.size() == M) {
    result = min(result, getChickenDistance(selected));
    return ;
  }

  for(int i=start;i<chickens.size();i++) {
    // 현재 치킨집을 선택
    selected.push_back(chickens[i]);
    // 다음 치킨집 선택을 위해 재귀
    chooseChickens(i+1, selected);
    // 백트래킹: 선택한 치킨집을 다시 제거
    selected.pop_back();
  }
}

int main()
{
  // INPUT
  cin >> N >> M;
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      int type;
      cin >> type;
      if (type == 1)
        houses.push_back(make_pair(i,j));
      else if (type == 2)
        chickens.push_back(make_pair(i,j));
    }
  }

  vector<pii> selected;
  chooseChickens(0, selected);

  cout << result << endl;
  return 0;
}

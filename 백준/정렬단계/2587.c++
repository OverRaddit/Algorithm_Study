#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
  int a;
  for(int i=0;i<5;i++){
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  // v를 순회하며 전체 합을 구한다.
  int sum = 0;
  for(int i=0;i<v.size();i++){
    sum += v[i];
  }

  // 평균
  cout << sum / v.size() << endl;
  // 중앙값
  cout << v[v.size() / 2] << endl;
}

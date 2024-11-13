#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int N,K;

int main()
{
  cin >> N >> K;
  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    v.push_back(a);
  }

  // 내림차순 정렬
  sort(v.begin(), v.end(), greater<int>());

  cout << v[K - 1] << endl;
}

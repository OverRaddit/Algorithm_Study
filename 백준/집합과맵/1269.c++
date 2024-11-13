#include <iostream>
#include <set>
using namespace std;

int A,B, N=0;
int arrA[400000] = {0};
// int arrA[200000] = {0};
// int arrB[200000] = {0};
set<int> s;

int main()
{
  // INPUT
  cin >> A >> B;
  for(int i=0;i<A+B;i++) {
    cin >> arrA[i];
    pair<set<int>::iterator, bool> ret = s.insert(arrA[i]);
    if (ret.second) {
      N++;
    } else {
      N--;
    }
  }

  cout << N << endl;
}

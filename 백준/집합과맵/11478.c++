#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> answer;

int main()
{
  // len <= 1000 = 10^3
  string str;
  cin >> str;

  // O(N^2) * substr
  // substr - O(j-i+1)
  for(int i=0;i<str.size();i++) {
    for(int j=i;j<str.size();j++) {
      answer.insert(str.substr(i, j-i+1));
    }
  }
  cout << answer.size() << endl;
}

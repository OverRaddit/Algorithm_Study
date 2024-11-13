#include <iostream>
#include <algorithm>
#include <deque>
#include <sstream>

using namespace std;

deque<int> v;
int N;
stringstream output;

int main()
{
  cin >> N;

  for(int i=0;i<N;i++){
    int x,y;
    cin >> x;
    switch(x){
      case 1:
        cin >> y;
        v.push_front(y);
        break;
      case 2:
        cin >> y;
        v.push_back(y);
        break;
      case 3:
        if(v.empty()) {
          output << "-1\n";
          break;
        }
        output << v.front() << "\n";
        v.pop_front();
        break;
      case 4:
        if(v.empty()) {
           output << "-1\n";
           break;
          }
        output << v.back() << "\n";
        v.pop_back();
        break;
      case 5:
        output << v.size() << "\n";
        break;
      case 6:
        output << (v.empty() ? 1 : 0) << "\n";
        break;
      case 7:
        if(v.empty()) {
           output << "-1\n";
           break;
          }
        output << v.front() << "\n";
        break;
      case 8:
        if(v.empty()) {
           output << "-1\n";
           break;
          }
        output << v.back() << "\n";
        break;
      default:
        break;
    }
  }
  cout << output.str();
}
/*

- 문자열스트림을 사용해보았다.

*/

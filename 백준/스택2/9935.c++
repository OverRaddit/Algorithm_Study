#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str,explode;

// 브루트 포스 - 시간초과
void brute_force()
{
  while(1) {
    int pos = str.find(explode);

    if (pos == string::npos) break;
    string front = str.substr(0, pos);
    // string back = str.substr(pos, pos + explode.length() - 1);
    string back = str.substr(pos + explode.length());

    // cout << "front: " << front << endl;
    // cout << "back: " << back << endl;

    str = front + back;
  }

  // OUTPUT
  if(str.length() == 0)
    cout << "FRULA" << endl;
  else
    cout << str << endl;
}

int main()
{
  // INPUT
  cin >> str; // 10^6
  cin >> explode; // ~36, 중복문자없음

  // PROCESS
  stack<char> s;
  stack<char> bucket;
  for(int i=0;i<str.size();i++) {
    s.push(str[i]);

    if(s.size() < explode.length()) continue;

    // 만약 스택위에서 부터 n글자가 explode와 일치하면
    for(int j=explode.length()-1;j>=0;j--) {
      if (s.top() == explode[j]) {
        bucket.push(s.top());
        s.pop();
      }
    }
    if (bucket.size() == explode.length())
      while(!bucket.empty()) bucket.pop();
    else {
      while(!bucket.empty()) {
        s.push(bucket.top());
        bucket.pop();
      }
    }
  }

  // OUTPUT
  if(s.size() == 0)
    cout << "FRULA" << endl;
  else {
    string answer;
    while(!s.empty()) {
      answer += s.top();
      s.pop();
    }
    // answer 거꾸로 읽기.
    for(int i=answer.size()-1;i>=0;i--)
      cout << answer[i];
  }
}
/*
mirkovC4nizCC44
mirkovnizC4
mirkovniz

이게 왜... 스택이지?
우선 브루트포스로 간다. -> 시간초과 ㅎㅎ;;

두 문자열을 입력받고
스택에 원본문자열을 쌓으면서, 스택맨위에 폭발문자열이 쌓일때마다 제거하면?
*/

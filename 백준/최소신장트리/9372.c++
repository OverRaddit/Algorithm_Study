#include <iostream>
#include <vector>
using namespace std;

int T;
vector<pair<int,int> > edges;
vector<int> answers;

/*
이 문제 어이가 없는게 ㅋㅋㅋ
그냥 N-1 출력하면 정답임;;
*/

void Solve()
{
  // INPUT
  int N,M,a,b;
  cin >> N >> M;
  for(int i=0;i<M;i++) {
    cin >> a >> b;
    edges.push_back(make_pair(a-1,b-1));
    edges.push_back(make_pair(b-1,a-1));
  }
  answers.push_back(N-1);
}

int main()
{
  cin >> T;
  for(int i=0;i<T;i++) {
    Solve();
  }
  for(int i=0;i<answers.size();i++)
    cout << answers[i] << "\n";
}

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N;
// deque<int> v;
deque<pair<int,int> > v;
vector<int> answer;

// 덱의 front를 back으로 이동시킨다.
void rotateFront()
{
  pair<int,int> pop = v.front();
  v.pop_front();
  v.push_back(pop);
}

// 덱의 back을 front로 이동시킨다.
void rotateBack()
{
  pair<int,int> pop = v.back();
  v.pop_back();
  v.push_front(pop);
}

void printDeque()
{
  for(int i=0;i<v.size();i++)
    cout << v[i].first;
  cout << endl;
}

int main()
{
  // INPUT
  cin >> N;
  for(int i=0;i<N;i++)
  {
    int a;
    cin >> a;
    // v.push_back(a);
    v.push_back(make_pair(i+1,a));
  }

  while(!v.empty())
  {
    int num = v.front().first;
    int val = v.front().second;

    v.pop_front();
    answer.push_back(num);
    // cout << num << " ";

    if (v.empty()) break;

    // ⭐️ 양수일때는 val-1, 음수일때는 -1*val만큼가는게 문제의 핵심.
    if (val > 0) {
      for(int i=0;i<val - 1;i++) {
        rotateFront();
      }
    } else {
      for(int i=0;i< -1 * val;i++) {
        rotateBack();
      }
    }

    // printDeque();
  }

  for(int i=0;i<answer.size();i++)
    cout << answer[i] << " ";
  cout << endl;
}

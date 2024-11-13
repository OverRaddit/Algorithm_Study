#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int N,C;
int answer;
vector<int> v;

void origin_one()
{
  answer = 1; // 가방에 아무것도 넣지 않는 케이스.
  sort(v.begin(), v.end());

  // 엣지케이스 - 가방에 담을 수 있는 물건이없음.
  if (C < v[0]) {
    cout << 1 << endl;
    return ;
  }

  // 투포인터 - 부분수열의 개수를 카운팅한다.
  int left = 0, right = 0;
  long long sum = v[0]; // v[0]을 더하고 시작하니까 answer도 하나늘리고가야하나;;
  if (sum == C) right = 1;
  while(left <= right && right <= v.size()) {
    if (sum < C) { // 모자라면
      sum += v[++right]; // 담는다
      answer++;
      cout << "[a]" << left << " " << right << endl;
    } else {
      if (sum == C) {
        cout << "[b]" << left << " " << right << endl;
        // answer++;
      }
      sum -= v[left++];
    }
  }
}

// 입력데이터를 절반으로 나누고, 반씩 나뉜 데이터들 간의 sum의 모든 조합을 구한다.
void dfs(int s, int e, vector<ll>& arr, ll sum) {
  if (s > e) {
    arr.push_back(sum);
    return;
  }

  // arr[s]를 포함하는 경우
  dfs(s + 1, e, arr, sum);
  // arr[s]를 포함하지 않는 경우
  dfs(s + 1, e, arr, sum + v[s]);
}

int main()
{
  cin >> N >> C; // N은 1~30, C는 10^9이하
  v.resize(N, 0);
  for(int i=0;i<N;i++) {
    cin >> v[i];
  }

  vector<ll> first;
  vector<ll> second;

  dfs(0, N/2-1, first, 0);
  dfs(N/2, N-1, second, 0);

  // first, second를 출력한다.
  // for(int i=0;i<first.size();i++) {
  //   cout << first[i] << " ";
  // }
  // cout << endl;
  // for(int i=0;i<second.size();i++) {
  //   cout << second[i] << " ";
  // }
  // cout << endl;

  sort(second.begin(), second.end());
  for(int i=0;i<first.size();i++) {
    ll rest = C - first[i];

    answer += upper_bound(second.begin(), second.end(), rest) - second.begin();
    // cout << "rest: " << rest << " " << upper_bound(second.begin(), second.end(), rest) - second.begin() << endl;
  }

  cout << answer << endl;
}

/*
N=8, [0, 3], [4, 7]
N=7, [0, 2], [3, 7]
*/

#include <vector>
#include <iostream>
#define MAX_PLAYER_NUM 100000
#define MAX_NUM 1000000

using namespace std;

int N, max_card = -1;
int arr[MAX_PLAYER_NUM] = {0}; // i번째 플레이어의 카드숫자
bool exist[MAX_NUM + 1] = {0}; // 카드숫자를 가진 플레이어가 존재하는지 여부
int score[MAX_NUM + 1] = {0}; // 카드숫자를 가진 플레이어의 점수

int main()
{
  cin >> N;
  for(int i=0;i<N;i++) {
    cin >> arr[i];
    exist[arr[i]] = 1;
    max_card = max(max_card, arr[i]);
  }

  // O(NlgN)
  for(int i=0;i<N;i++) {
    int num = arr[i];
    // O(lgN)
    for(int x = num*2; x<=max_card;x+=num) {
      if (exist[x]) {
        score[x] -= 1;
        score[num] += 1;
      }
    }
  }

  for(int i=0;i<N;i++)
    cout << score[arr[i]] << " ";
}

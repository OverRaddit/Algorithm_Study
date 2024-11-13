#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N,tmp;
int arr[10] = {0};

int maxFruitsWithTwoTypes(const vector<int>& fruits) {
  unordered_map<int, int> fruitCount;
  int maxLen = 0;
  int left = 0; // left pointer of the window

  for (int right = 0; right < fruits.size(); ++right) {
    // Add the right fruit to the map
    fruitCount[fruits[right]]++;

    // Shrink the window from the left if more than 2 types are present
    while (fruitCount.size() > 2) {
      fruitCount[fruits[left]]--;
      if (fruitCount[fruits[left]] == 0) {
        fruitCount.erase(fruits[left]);
      }
      left++; // Move left pointer to the right
    }

    // Update maximum length of the window
    maxLen = max(maxLen, right - left + 1);
  }

  return maxLen;
}

// 현재 덱에 들어있는 과일의 종류 수를 구한다.
int getNumofFruit()
{
  int ret = 0;
  for(int i=1;i<=9;i++) {
    if (arr[i] != 0) ret++;
  }
  return ret;
}

int main()
{
  // 200000, 각원소는 1~9
  vector<int> v;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> tmp;
    v.push_back(tmp);
    arr[tmp] += 1;
  }

  int answer = maxFruitsWithTwoTypes(v);
  cout << answer << endl;
}



// 현재 몇종류인지?

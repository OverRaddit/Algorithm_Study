#include <iostream>
#include <string>
using namespace std;

int DP[1001][1001] = {0}; // DP[x][y] = A의 x번째글자, B의 y번째 글자로 만들 수 있는 LCS의 길이.

int main()
{
	ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string A, B;
  cin >> A >> B;

	// 좌측상단에서 우측하단으로, DP를 완성한다.
	int N = A.size();
	int M = B.size();
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (A[i - 1] == B[j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else
			{
				DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
			}
		}
	}

	string Solution;

	// 우츠
	int i = N;
	int j = M;
	while (i > 0 && j > 0)
	{
		if (DP[i][j] == DP[i - 1][j])
		{
			--i;
		}
		else if (DP[i][j] == DP[i][j - 1])
		{
			--j;
		}
		else
		{
			Solution.push_back(A[i - 1]);
			--i;
			--j;
		}
	}

	cout << Solution.size() << '\n';
	for (int i = Solution.size() - 1; i >= 0; --i)
	{
		cout << Solution[i];
	}
}

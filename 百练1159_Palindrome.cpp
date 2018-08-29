// 回文串（此题为动态规划求最长公共子序列加滚动数组）

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n;
char L[6000];
char D[6000];
int maxl[2][6000] = { 0 };

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> L[i];
	L[n + 1] = '\0';
	for (int i = 1; i <= n; ++i)
		D[i] = L[n + 1 - i];
	int e = 0; // 滚动数组,因为每个maxl[i][j]都只用一次

	// 动态规划求最长公共子序列，maxl[i][j] = max(maxl[i-1][j], maxl[i][j-1])
	for (int i = 1; i <= n; ++i)
	{
		e = 1 - e;
		for (int j = 1; j <= n; ++j)
		{
			if (L[i] == D[j])
				maxl[e][j] = maxl[1 - e][j - 1] + 1;
			else
				maxl[e][j] = max(maxl[e][j - 1], maxl[1 - e][j]);
		}
	}
	cout << n - maxl[e][n] << endl;
	return 0;
}
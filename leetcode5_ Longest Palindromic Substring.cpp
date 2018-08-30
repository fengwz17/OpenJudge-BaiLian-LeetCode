// 求最长回文串，第一个方法求最长公共子串是错的：abcxyzcba
#include<stdlib.h>
#include<cstring>
#include<string.h>
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
int n;

//char L[1000001];
//char D[1000001];

string L;
string D;
int maxl[2][1000001];
int imax;
int main()
{
	int count = 0;
	while (cin >> L && L != "END")
	{
		memset(maxl, 0, sizeof(maxl));
		count++;
		int len = L.length();
		D.assign(L.rbegin(), L.rend());
		int e = 0;
		imax = 0;
		
		for (int i = 0; i <= len; ++i)
		{

			for (int j = 0; j <= len; ++j)
			{
			
				if (i == 0 || j == 0)
					maxl[e][j] = 0;

				else if (L[i-1] == D[j-1])
				{
					maxl[e][j] = maxl[1 - e][j - 1] + 1;
					imax = max(imax, maxl[e][j]);
				}

				else
				{
					maxl[e][j] = 0;
				}
			}
			e = 1 - e;
		}

		cout << "case " << count << ": " << imax << endl;
	}
	
	return 0;
}
*/

int dp[1000001][2];
// 动态规划, 在poj上面超时了,只能过leetcode5最长子串
string longestPalindrome(string s)
{
	const int n = s.size();
	
	int e = 0;
	int maxlen = 1;
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (i - j < 2)
				dp[j][e] = (s[i] == s[j]);
			else
				dp[j][e] = (s[i] == s[j] && dp[j + 1][1 - e]);
			if (dp[j][e] && (maxlen < i - j + 1))
			{
				maxlen = i - j + 1;
				start = j;
			}
		}
		e = 1 - e;
	}
	return s.substr(start, maxlen);
	//return maxlen;
}

int main()
{
	string s;
	//int count = 0;
	//while(cin >> s && s != "END")
	//{
		//count++;
		//memset(dp, 0, sizeof(dp));
		//cout << "Case " << count << ": " << longestPalindrome(s) << endl;
	//}
	cin >> s;
	cout << longestPalindrome(s) << endl;
	return 0;
}
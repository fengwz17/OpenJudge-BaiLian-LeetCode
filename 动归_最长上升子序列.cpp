/*
最长上升子序列
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1010;
int a[MAXN];
int maxLen[MAXN];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> a[i];
		maxLen[i] = 1;

	}
	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (a[i] > a[j])
			{
				maxLen[i] = max(maxLen[i], maxLen[j] + 1);
			}
			
		}
	}
	// 这样写也可以
	// for(int i = 1; i <=N; ++i)
			// for(int j = i+1; j <= N;++j)
				// if(a[j] > a[i])
					// maxLen[j] = max(maxLen[j], maxLen[i]+1)

	cout << *max_element(maxLen + 1, maxLen + N + 1);
	return 0;

}
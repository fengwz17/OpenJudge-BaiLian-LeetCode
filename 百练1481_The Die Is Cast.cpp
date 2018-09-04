#include<string>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int w, h;

char x[60][60];
int num[100] = { 0 };
int dx[4] = { 0 ,0 , -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int l = 0;
int count1 = 0;

// 搜索"X"
void dfs2(int t, int k)
{
	x[t][k] = '*';
	for (int i = 0; i < 4; ++i)
	{
		int xx = t + dx[i];
		int yy = k + dy[i];
		if (xx >= 1 && xx <= h && yy >= 1 && yy <= w && x[xx][yy] == 'X')
			dfs2(xx, yy);
	}
}

// 搜索"*"
void dfs1(int t, int k)
{
	x[t][k] = '.';
	for (int i = 0; i < 4; ++i)
	{
		int xx = t + dx[i];
		int yy = k + dy[i];

		// 出界,continue找下一个i
		if (xx < 1 || xx > h || yy < 1 || yy > w || x[xx][yy] == '.')
			continue;
		if (x[xx][yy] == 'X')
		{
			dfs2(xx, yy);
			num[l]++;
		}
		if (x[xx][yy] == '*')
			dfs1(xx, yy);
	}
}




int main()
{
	while (cin >> w >> h && (w != 0 && h != 0))
	{
		count1++;
		l = 0;
		memset(x, 0, sizeof(x));
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= h; ++i)
			for (int j = 1; j <= w; ++j)
			{
				cin >> x[i][j];
			}
		for(int i = 1; i <= h; ++i)
			for (int j = 1; j <= w; ++j)
			{
				if (x[i][j] == '*')
				{
					dfs1(i, j);
					l++;
				}
			}
		sort(num, num + l);
		cout << "Throw" << ' ' << count1 << endl;
		for(int i = 0; i < l - 1; i++)
			cout << num[i] << ' ';
		cout << num[l - 1] << endl;
		cout << endl;
	}
	return 0;
}

// Dijkstra算法或者Floyd算法求最短路
// 本题主要难点在于理解题意 
// w设为路径长度，直接指向时w=0, 需要手动扳动时w=1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#define INF 0xffff;
using namespace std;

int map[100][100];

int main()
{
	int n, a, b;
	int k, x;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			map[i][j] = map[j][i] = INF;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> x;
			map[i][x] = j == 1 ? 0 : 1; // 对每个路口，第一个（原指向路口）为0，之后（再需要进行转换的）指向的路口为1
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	if ( map[a][b] == 0xffff )
		cout << "-1" << endl;
	else
		cout << map[a][b] << endl;

	return 0;
}
 

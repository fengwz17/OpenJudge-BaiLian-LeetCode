/*
#输入
输入包括多组数据：一个矩形b板对应一组数据
第一行包括两个整数w和h(1 <= w, h <= 75)，分别表示矩形板的宽度和长度
下面h行，每行包括w个字符，表示矩形板上的游戏卡片分布，X表示这个地方有一个游戏卡片，空格表示这个地方没有卡片
之后每行包括4个整数：x1, y1, x2, y2(1 <= x1, x2 <= w, 1 <= y1, y2 <= h)给出两个卡片在矩形板上的位置，矩形板左上角是(1, 1)
输入保证这两个游戏卡片所处的位置是不相同的
如果一行上有4个0, 表示这组测试数据的结束
如果一行上给出w = h = 0, 那么表示所有的输入结束了

#输出
对每一个矩形板, 输出一行 “Board #n:”, n是输入数据的编号
对每一组需要测试的游戏卡片输出一行.这一行的开头是 “Pair m : ”, 这里m是测试卡片的编号（对每个矩形板, 编号都从1开始）
如果可以相连, 找到连接这两个卡片的所有路径中包括线段数最少的路径, 输出 “k segments.”
k是找到的最优路径中包括的线段的数目
如果不能相连, 输出 “impossible.”
每组数据之后输出一个空行

#样例输入
5 4
XXXXX
X   X
XXX X
XXX
2 3 5 3
1 3 4 4
2 3 3 4
0 0 0 0
0 0

#样例输出
Board #1:
Pair1: 4 segments
Pair2 : 3 segments
Pair3 : impossible

下面代码有问题
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
# define MAXIN 75

using namespace std;

char board[MAXIN + 2][MAXIN + 2];
int minstep, w, h, to[4][2] = { {0,1},{1,0},{0,0},{1,1} };
bool mark[MAXIN + 2][MAXIN + 2];

void Search(int now_x, int now_y, int end_x, int end_y, int step, int f)
{
	if (step > minstep)
		return;
	if (now_x == end_x && now_y == end_y)
	{
		if (minstep > step)
			minstep = step;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int x = now_x + to[i][0];
		int y = now_y + to[i][1];
		if ((x > -1) && (x < w + 2) && (y > -1) && (y < h + 2)
			&& (((board[y][x] == ' ') && (mark[y][x] == false)) ||
			((x == end_x) && (y == end_y) && (board[y][x] == 'X'))))
		{
			mark[y][x] = true;
			if (f == i) Search(x, y, end_x, end_y, step, i);
			else Search(x, y, end_x, end_y, step + 1, i);
			mark[y][x] = false;
		}
	}
}

int main()
{
	int Boardnum = 0;
	while (cin >> w >> h)
	{
		if (w == 0 && h == 0)
			break;
		Boardnum++;
		cout << "Board #: " << Boardnum << endl;
		int i, j;
		for (i = 0; i < MAXIN + 2; i++)
			board[0][i] = board[i][0] = ' ';
		for (i = 1; i <= h; i++)
		{
			getchar();
			for (j = 1; j <= w; j++)
				board[i][j] = getchar();
		}

		for (i = 0; i <= w; i++)
			board[h + 1][i + 1] = ' ';
		for (i = 0; i <= h; i++)
			board[i + 1][w + 1] = ' ';
		for (i = 0; i <= w; i++)
		{
			for (j = 0; j <= h; j++)
				cout << board[i][j];
			cout << board[i][h+1] << endl;
		}
				
		int begin_x, begin_y, end_x, end_y, count = 0;
		while (cin >> begin_x >> begin_y >> end_x >> end_y && begin_x > 0)
		{
			count++;
			minstep = 100000;
			memset(mark, false, sizeof(mark));
			Search(begin_x, begin_y, end_x, end_y, 0, -1);
			if (minstep < 100000)
				cout << "Pair " << count << ": " << minstep << " segments" << endl;
			else
				cout << "Pair " << count << ": impossible" << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}







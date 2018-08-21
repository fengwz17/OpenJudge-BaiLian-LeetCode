/*
灌溉农场
在一片草场上:有一条长度为L (1 <= L <= 1,000,000，L为偶数)的线段。 John的N (1 <= N <= 1000) 头奶牛都沿着草场上这条线段吃草，每头牛的活动范围是一个开区间(S,E)，S，E都是整数。不同奶牛的活动范围可以有重叠。
John要在这条线段上安装喷水头灌溉草场。每个喷水头的喷洒半径可以随意调节，调节范围是 [A B ](1 <= A <= B <= 1000)，A,B都是整数。要求
线段上的每个整点恰好位于一个喷水头的喷洒范围内
每头奶牛的活动范围要位于一个喷水头的喷洒范围内
任何喷水头的喷洒范围不可越过线段的两端(左端是0,右端是L )
请问， John 最少需要安装多少个喷水头。

输入
第1行：整数N、L。
第2行：整数A、B。
第3到N+2行：每行两个整数S、E (0 <= S < E <= L) ，
表示某头牛活动范围的起点和终点在线段上的坐标(即到线段起点的距离)。

输出
最少需要安装的多少个喷水头；若没有符合要求的喷水头安装方案，则输出-1。

输入样例
2 8
1 2
6 7
3 6

输出样例
3
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstring>
#include<queue>

using namespace std;

const int INFINITE = 1 << 31;
const int MAXL = 1000010;
const int MAXN = 1010;
int F[MAXL];
int cowThere[MAXL]; // cowThere[i]=1表示i点有牛
int N, L, A, B;
struct Fx {
	int x;
	int f;
	bool operator<(const Fx & a) const { return f > a.f; }
	Fx(int xx = 0, int ff = 0) :x(xx), f(ff) {}
}; // 优先队列，f值越小越优先
priority_queue<Fx> qFx;

int main()
{
	cin >> N >> L;
	cin >> A >> B;
	A = A << 1; // A,B定义为直径
	B = B << 1;
	memset(cowThere, 0, sizeof(cowThere));
	for (int i = 0; i < N; i++)
	{
		int s, e;
		cin >> s >> e;
		++cowThere[s + 1]; // 从s+1起进入一个奶牛区
		--cowThere[e]; // 从e起退出一个奶牛区
	}
	int inCows = 0; // 表示当前点位于多少头奶牛的活动范围之内
	for (int i = 0; i <= L; i++) // 算出每个点是否有奶牛
	{
		F[i] = INFINITE;
		inCows += cowThere[i];
		cowThere[i] = inCows > 0;
	}
	for (int i = A; i <= B; i += 2) //初始化队列
	{
		if (!cowThere[i])
		{
			F[i] = 1;
			if (i <= B + 2 - A) //在求F[i]的时候，要确保队列里的点x，x <= i - A
				qFx.push(Fx(i, 1));
		}
	}
	for (int i = B + 2; i <= L; i += 2)
	{
		if (!cowThere[i])
		{
			Fx fx;
			while (!qFx.empty())
			{
				fx = qFx.top();
				if (fx.x < i - B)
					qFx.pop();
				else
					break;
			}
			if (!qFx.empty())
				F[i] = fx.f + 1;
		}
		if (F[i - A + 2] != INFINITE) // 队列中增加一个+1可达下个点的点
		{
			qFx.push(Fx(i - A + 2, F[i - A + 2]));
		}
	}
	if (F[L] == INFINITE)
		cout << -1 << endl;
	else
		cout << F[L] << endl;
	return 0;
}



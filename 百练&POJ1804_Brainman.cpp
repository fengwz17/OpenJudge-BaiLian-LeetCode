// 求逆序对，归并排序
// 北大百练过不了（wrong anwser），poj能过
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
#include<cstring>
#include<string>
#include<stdio.h>
using namespace std;

int casen = 0;
int num = 0;
int x[100001];
int temp[100001];
long long icount;

void merge(int x[], int left, int mid, int right, int temp[])
{
	int i = left;
	int j = mid + 1;
	int point = 0;

	/*
	while (i <= mid && j <= right)
	{
		if (x[i] <= x[j])
		{
			temp[point++] = x[i++];
		}
		else
		{
			temp[point++] = x[j++];
			icount += mid - i + 1;
		}
	}

	while (i <= mid)
	{
		temp[point++] = x[i++];
	}
	while (j <= right)
	{
		temp[point++] = x[j++];
	}
	for (int t = 0; t < point; t++)
	{
		x[t + left] = temp[t];
	}
	*/
	while (i <= mid || j <= right)
	{
		if (j > right || (i <= mid && x[i] <= x[j]))
			temp[point++] = x[i++];
		else
		{
			temp[point++] = x[j++];
			icount += mid - i + 1;
		}
	}
	for (int t = 0; t < point; t++)
	{
		x[t + left] = temp[t];
	}
}

void merge_sort(int a[], int left, int right, int c[])
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(a, left, mid, c);
		merge_sort(a, mid + 1, right, c);
		merge(a, left, mid, right, c);
	}
}

int main()
{
	cin >> casen;
	int c = 0;
	c = casen;
	while (casen--)
	{
		cin >> num;
		icount = 0;
		memset(temp, 0, sizeof(temp));
		for (int i = 0; i < num; ++i)
		{
			scanf("%d", &x[i]);
		}
		merge_sort(x, 0, num - 1, temp);
		//cout << "Scenario #" << c - casen << ":" << endl;
		//cout << icount << endl;
		//cout << endl;
		printf("Scenario #%d:\n", c - casen);
		printf("%lld\n", icount);
		printf("\n");
	}
	return 0;
}
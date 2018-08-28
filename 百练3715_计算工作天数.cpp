
#include <iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include <vector> 
using namespace std;

bool run(int a)
{
	if (a % 100 == 0)
	{
		if (a % 400 == 0)
			return true;
		else
			return false;
	}
	else
	{
		if (a % 4 == 0)
			return true;
		else
			return false;
	}
}
bool flag(int a)
{
	if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12)
	{
		return 1;
	}
	else
		return 0;
}

int cal(int y, int m1, int d1, int m2, int d2)
{
	int c;

	if (m1 == m2)
	{
		c = d2 - d1 + 1;
	}
	else if (m1 + 1 == m2)
	{
		if (flag(m1))
		{
			c = 31 - d1 + 1 + d2;
		}
		else if (m1 == 2)
		{
			if (run(y))
				c = 29 - d1 + 1 + d2;
			else
				c = 28 - d1 + 1 + d2;
		}
		else
			c = 30 - d1 + 1 + d2;
	}
	else
	{
		for (int i = m1; i <= m2 - 1; ++i)
		{
			if (i == m1)
			{
				if (flag(i))
					c = 31 - d1 + 1 + d2;
				else if (m1 == 2)
				{
					if (run(y))
						c = 29 - d1 + 1 + d2;
					else
						c = 28 - d1 + 1 + d2;
				}
				else
				{
					c = 30 - d1 + 1 + d2;
				}
			}
			else {
				if (flag(i))
					c = c + 31;
				else if (i == 2)
				{
					if (run(y))
						c += 29;
					else
						c += 28;
				}
				else
					c += 30;
			}
		}
	}
	return c;
}

typedef struct em {
	string name;
	int num;
} EM;

vector<EM> em;

int isShorter(const EM &a, const EM &b)
{
	return a.num > b.num;
}

int main()
{
	int N;
	int N1;
	int a[3] = { 0 };
	int b[3] = { 0 };
	int count[1000] = { 0 };
	cin >> N;
	N1 = N;
	while (N--)
	{
		EM one;
		count[N] = 0;
		cin >> one.name;
		cin >> a[0] >> a[1] >> a[2];
		cin >> b[0] >> b[1] >> b[2];
		if (a[0] == b[0])
		{
			count[N] = cal(a[0], a[1], a[2], b[1], b[2]);
		}
		else if (a[0] + 1 == b[0])
		{
			count[N] = cal(a[0], a[1], a[2], 12, 31) + cal(b[0], 1, 1, b[1], b[2]);
		}
		else {
			for (int i = a[0] + 1; i <= b[0] - 1; i++)
			{
				count[N] = count[N] + run(i) + 365;
			}
			count[N] = count[N] + cal(a[0], a[1], a[2], 12, 31) + cal(b[0], 1, 1, b[1], b[2]);
		}

		one.num = count[N];
		em.push_back(one);
	}
	stable_sort(em.begin(), em.end(), isShorter);
	for (vector<EM>::iterator it = em.begin(); it != em.end(); it++)
	{
		cout << it->name << ' ' << it->num << endl;
	}
	return 0;
}


/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int month_1[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // 正常年的月份
int month_2[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 }; // 闰年的月份
int n, year_in, year_out, day_in, day_out, month_in, month_out;

typedef struct employee {
	string name;
	int days_in_company;
} EMPLOYEE;

vector<EMPLOYEE> employee_vec;

bool is_leap_year(int year) { // 闰年返回1，否则返回0
	if (year % 4 == 0) {
		if ((year % 100 == 0) && (year % 400 != 0))
			return false;
		return true;
	}
	return false;
}

int count_days() {
	int days = 0;
	days += (is_leap_year(year_in) ? month_2[month_in] : month_1[month_in]) - day_in + 1;
	for (int i = month_in + 1; i < 13; ++i) {
		if (is_leap_year(year_in))
			days += month_2[i];
		else
			days += month_1[i];
	}
	for (int i = year_in + 1; i <= year_out; ++i) {
		if (is_leap_year(i))
			days += 366;
		else
			days += 365;
	}

	days -= (is_leap_year(year_out) ? month_2[month_out] : month_1[month_out]) - day_out;
	for (int i = month_out + 1; i < 13; ++i) {
		if (is_leap_year(year_out))
			days -= month_2[i];
		else
			days -= month_1[i];
	}
	return days;
}

int isShorter(const EMPLOYEE &a, const EMPLOYEE &b) {
	return a.days_in_company > b.days_in_company;
}

int main() {
	cin >> n;
	while (n--) {
		EMPLOYEE one;
		cin >> one.name;
		cin >> year_in >> month_in >> day_in >> year_out >> month_out >> day_out;
		one.days_in_company = count_days();
		employee_vec.push_back(one);
	}
	stable_sort(employee_vec.begin(), employee_vec.end(), isShorter);
	for (vector<EMPLOYEE>::iterator it = employee_vec.begin(); it != employee_vec.end(); ++it) {
		cout << (*it).name << " " << (*it).days_in_company << endl;
	}
	return 0;
}
*/
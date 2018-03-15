// CCF.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int MAXN = 1000;
const int INF = 1 << 30;

int main()
{
	int n;
	cin >> n;
	int a[1008];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int temp = a[i];
		int small = 0, large = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] < temp)
			{
				small++;
			}
			else if (a[j]>temp)
			{
				large++;
			}
		}
		if (small == large)
		{
			cout << temp << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}

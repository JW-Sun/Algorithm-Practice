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
	int a[1005];
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int num = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum >= k)
		{
			sum = 0;
			num++;
		}
		sum += a[i];
	}
	if (sum>0)
	{
		num++;
	}
	cout << num;
	return 0;
}


/*int main()
{
	int n, k,a;
	int aa = 0;
	int num = 0;
	cin >> n >> k;
	queue<int>q;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		q.push(a);
	}
	while (!q.empty())
	{
		aa += q.front();
		q.pop();
		if (aa >= k)
		{
			num++;
			aa = 0;
		}
	}
	num++;
	cout << num << endl;;
	return 0;
}*/




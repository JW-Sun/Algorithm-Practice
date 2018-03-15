// CCF.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	queue<int>q;
	int n, k;
	int nn=1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	while (q.size() > 1)
	{
		int top = q.front();
		q.pop();
		if (nn%k != 0 && (nn - nn / 10*10 )!= k)
		{
			q.push(top);
		}
		nn++;
	}
	cout << q.front();
	return 0;
}





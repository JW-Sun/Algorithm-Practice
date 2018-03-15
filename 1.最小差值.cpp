// CCF.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1000];
	int minn = 10000;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			int temp = abs(a[i] - a[j]);
			if (temp < minn)
			{
				minn = temp;
			}
		}
	}
	cout << minn;
	return 0;
}





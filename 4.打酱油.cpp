// CCF.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	int money;
	int count = 0;
	cin >> money;
	int n = money / 10;
	while (n >= 5)
	{
		count += 7;
		n -= 5;
	}
	while (n >= 3)
	{
		count += 4;
		n -= 3;
	}
	cout << count+n;
	return 0;
}




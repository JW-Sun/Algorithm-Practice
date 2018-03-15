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
const int INF = 1e10;
int N;
int a;
int b;
queue<int>q;


int main()
{
	cin >> N;
	for (int i = 0; i < N;i++){
		cin >> a;
		switch (a)
		{
		case 1:
			cin >> b;
			q.push(b);
			break;
		case 2:
			if (!q.empty())
			{
				int c = q.front();
				q.pop();
				cout << c << endl;
			}
			else
			{
				cout << "no" << endl;
				return 0;
			}
			break;
		case 3:
			cout << q.size() << endl;
			break;
		}
	}

	return 0;
}


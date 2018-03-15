// CCF.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct key
{
	int id;
	int time;
	int flag;
};

bool compare(key k1, key k2)
{
	if (k1.time != k2.time)
	{
		return k1.time < k2.time;
	}
	else if (k1.flag != k2.flag)
	{
		return k1.flag>k2.flag;
	}
	else
	{
		return k1.id < k2.id;
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	vector<key>v;
	for (int i = 0; i < b; i++)
	{
		int kid, t, tt;
		cin >> kid >> t >> tt;
		key k;
		k.id = kid;
		k.time = t;
		k.flag = 0;
		v.push_back(k);
		k.id = kid;
		k.time = t + tt;
		k.flag = 1;
		v.push_back(k);
	}
	sort(v.begin(), v.end(), compare);
	int sz[10000];
	for (int i = 1; i <= a; i++)
	{
		sz[i] = i;
	}
	for (int i = 0; i < v.size(); i++)
	{
		key k1 = v[i];
		int id = k1.id;
		int flag = k1.flag;
		if (flag == 0)
		{
			for (int i = 1; i <= a; i++)
			{
				if (sz[i] == id)
				{
					sz[i] = 0;
					break;
				}
			}
		}
		else if (flag == 1)
		{
			for (int i = 1; i <= a; i++)
			{
				if (sz[i] == 0)
				{
					sz[i] = id;
					break;
				}
			}
		}
	}
	cout << sz[1];
	for (int i = 2; i <= a; i++)
	{
		cout << " " << sz[i];
	}
	return 0;
}





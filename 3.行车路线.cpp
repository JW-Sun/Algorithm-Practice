// CCF.cpp : 定义控制台应用程序的入口点。
//
/*
问题描述

　　小明和小芳出去乡村玩，小明负责开车，小芳来导航。
 　　小芳将可能的道路分为大道和小道。大道比较好走，每走1公里小明会增加1的疲劳度。小道不好走，如果连续走小道，小明的疲劳值会快速增加，
 连续走s公里小明会增加s2的疲劳度。
 　　例如：有5个路口，1号路口到2号路口为小道，2号路口到3号路口为小道，3号路口到4号路口为大道，4号路口到5号路口为小道，
 相邻路口之间的距离都是2公里。如果小明从1号路口到5号路口，则总疲劳值为(2+2)2+2+22=16+2+4=22。
 　　现在小芳拿到了地图，请帮助她规划一个开车的路线，使得按这个路线开车小明的疲劳度最小。

输入格式

　　输入的第一行包含两个整数n, m，分别表示路口的数量和道路的数量。路口由1至n编号，小明需要开车从1号路口到n号路口。
 　　接下来m行描述道路，每行包含四个整数t, a, b, c，表示一条类型为t，连接a与b两个路口，长度为c公里的双向道路。
	其中t为0表示大道，t为1表示小道。保证1号路口和n号路口是连通的。

输出格式

　　输出一个整数，表示最优路线下小明的疲劳度。

样例输入

6 7
 1 1 2 3
 1 2 3 2
 0 1 3 30
 0 3 4 20
 0 4 5 30
 1 3 5 6
 1 5 6 1

样例输出

76

样例说明

　　从1走小道到2，再走小道到3，疲劳度为52=25；然后从3走大道经过4到达5，疲劳度为20+30=50；最后从5走小道到6，疲劳度为1。总共为76。
*/
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int m, n;
const long long INF = 1e18;
struct node
{
	int to;
	long long cost;
};

struct edge
{
	int id;
	long long cost;
	int len;
	bool operator<(const edge& a)const
	{
		return cost>a.cost;
	}
};

vector<node>G[510][2];
long long d[510];
priority_queue<edge>pq;
long long pp(long long a)
{
	return a*a;
}

int dj()
{
	fill(d, d + n + 1, INF);
	d[1] = 0;
	pq.push({ 1, 0, 0 });
	while (!pq.empty())
	{
		edge e = pq.top();
		pq.pop();
		int v = e.id;
		if (v == n)
		{
			break;
		}
		if (d[v] < e.cost)
			continue;
		for (int i = 0; i < G[v][0].size(); i++)
		{
			node nn = G[v][0][i];
			if (d[nn.to]>d[v] + nn.cost)
			{
				d[nn.to] = d[v] + nn.cost;
				pq.push(edge{ nn.to, d[nn.to], 0 });
			}
		}
		for (int i = 0; i < G[v][1].size(); i++)
		{
			node o = G[v][1][i];
			int cost = pp(e.len + o.cost) - pp(e.len);
			if (d[o.to]>d[v] + cost)
			{
				d[o.to] = d[v] + cost;
				pq.push(edge{ o.to, d[o.to], e.len + o.cost });
			}
		}
	}
	return d[n];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int t, a, b;
		long long c;
		cin >> t >> a >> b >> c;
		G[a][t].push_back({ b, c });
		G[b][t].push_back({ a, c });
	}
	cout << dj();
	return 0;
}







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

struct edge
{
	int type;
	int to;
	int len;
};
int n, m;
bool vis[MAXN] = { false };
int d[MAXN];
int x[MAXN];//到第i点走过的小路
vector<vector<edge>>G(MAXN);

void Dijkstra()
{
	fill(d, d + MAXN, INF);
	//fill(vis, vis + MAXN*MAXN, 0);
	fill(x, x + MAXN, 0);
	d[1] = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1;
		int MIN = INF;
		for (int j = 1; j <= n; j++)
		{
			if (vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)
		{
			return;
		}
		vis[u] = true;
		for (int k = 0; k < G[u].size(); k++)
		{
			if (G[u][k].type == 0)
			{
				if (d[u] + G[u][k].len < d[G[u][k].to])
				{
					d[G[u][k].to] = d[u] + G[u][k].len;
					x[G[u][k].to] = 0;
				}
			}
			else
			{
				int temp;
				if (x[u] == 0)
				{
					temp = G[u][k].len*G[u][k].len;
					if (d[u] + temp < d[G[u][k].to])
					{
						d[G[u][k].to] = d[u] + temp;
						x[G[u][k].to] = G[u][k].len;
					}
				}
				else
				{
					temp = (x[u] + G[u][k].len)*(x[u] + G[u][k].len);
					temp -= x[u] * x[u];
					if (d[u] + temp < d[G[u][k].to])
					{
						d[G[u][k].to] = d[u] + temp;
						x[G[u][k].to] = x[u] + G[u][k].len;
					}
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	int t, s, e, l;
	edge ee;
	for (int i = 0; i < m; i++)
	{
		cin >> t >> s >> e >> l;
		ee.type = t;
		ee.to = e;
		ee.len = l; 
		G[s].push_back(ee);
		ee.to = s;
		G[e].push_back(ee);
	}
	Dijkstra();
	cout << d[n];
	return 0;
}
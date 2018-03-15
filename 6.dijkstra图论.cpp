// CCF.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

const int MAXN = 512;
const int INF = 1000000;

int n, m, s, e;
int G[MAXN][MAXN];
bool vis[MAXN] = { false };
int d[MAXN];
int w[MAXN];
int num[MAXN];
int weight[MAXN];


void Dijstra(int s)
{
	fill(d, d + MAXN, INF);
	memset(num,0,sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for (int i = 0; i < n; i++)
	{
		int u = -1;
		int MIN = INF;
		for (int j = 0; j < n; j++)
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
		for (int k = 0; k < n; k++)
		{
			if (vis[k] == false && G[u][k] != INF)
			{
				if (d[u] + G[u][k] < d[k])
				{
					d[k] = d[u] + G[u][k];
					w[k] = w[u] + weight[k];
					num[k] = num[u];
				}
				else if (d[u] + G[u][k] == d[k])
				{
					if (w[u] + weight[k]>w[k])
					{
						w[k] = w[u] + weight[k];
					}
					num[k] += num[u] ;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m >> s >> e;
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}
	int start, end,ff;
	fill(G[0], G[0] + MAXN*MAXN, INF);
	for (int i = 0; i < m; i++)
	{
		//int start, end;
		cin >> start >> end >>ff;
		//cin >> G[start][end];
		G[end][start] = G[start][end]=ff;
	}
	Dijstra(s);
	cout << num[e] << " " << w[e];
	return 0;
}

/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1*/
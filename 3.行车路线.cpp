// CCF.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
��������

����С����С����ȥ����棬С�����𿪳���С����������
 ����С�������ܵĵ�·��Ϊ�����С��������ȽϺ��ߣ�ÿ��1����С��������1��ƣ�Ͷȡ�С�������ߣ����������С����С����ƣ��ֵ��������ӣ�
 ������s����С��������s2��ƣ�Ͷȡ�
 �������磺��5��·�ڣ�1��·�ڵ�2��·��ΪС����2��·�ڵ�3��·��ΪС����3��·�ڵ�4��·��Ϊ�����4��·�ڵ�5��·��ΪС����
 ����·��֮��ľ��붼��2������С����1��·�ڵ�5��·�ڣ�����ƣ��ֵΪ(2+2)2+2+22=16+2+4=22��
 ��������С���õ��˵�ͼ����������滮һ��������·�ߣ�ʹ�ð����·�߿���С����ƣ�Ͷ���С��

�����ʽ

��������ĵ�һ�а�����������n, m���ֱ��ʾ·�ڵ������͵�·��������·����1��n��ţ�С����Ҫ������1��·�ڵ�n��·�ڡ�
 ����������m��������·��ÿ�а����ĸ�����t, a, b, c����ʾһ������Ϊt������a��b����·�ڣ�����Ϊc�����˫���·��
	����tΪ0��ʾ�����tΪ1��ʾС������֤1��·�ں�n��·������ͨ�ġ�

�����ʽ

�������һ����������ʾ����·����С����ƣ�Ͷȡ�

��������

6 7
 1 1 2 3
 1 2 3 2
 0 1 3 30
 0 3 4 20
 0 4 5 30
 1 3 5 6
 1 5 6 1

�������

76

����˵��

������1��С����2������С����3��ƣ�Ͷ�Ϊ52=25��Ȼ���3�ߴ������4����5��ƣ�Ͷ�Ϊ20+30=50������5��С����6��ƣ�Ͷ�Ϊ1���ܹ�Ϊ76��
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







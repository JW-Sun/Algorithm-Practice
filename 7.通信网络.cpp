// CCF.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

#include <vector>

using namespace std;


vector<int>v[1024];
int IsConnect[1024][1024];


void DFS(int u, int vis[], int cur)
{
	vis[u] = 1;
	IsConnect[u][cur] =IsConnect[cur][u]= 1;
	for (int i = 0; i < v[u].size(); i++)
	{
		if (vis[v[u][i]]==0)
			DFS(v[u][i], vis, cur);
	}
}

int main()
{
	int n, m;
	int total = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
	}
	for (int i = 1; i <= n; i++)
	{
		int vis[1024] = { 0 };
		DFS(i, vis, i);
	}
	for (int i = 1; i <= n; i++)
	{
		int j;
		for (j = 1; j <= n; j++)
		{
			if (IsConnect[i][j] == 0)
			{
				break;
			}
			if (j == n+1)
			{
				total++;
			}
		}
	}
	cout << total;
	return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

vector<int> v[1024];
int isconnect[1024][1024];
void dfsSolve(int u,int visit[],int cur)
{
visit[u]=1;
isconnect[u][cur]=isconnect[cur][u]=1;
for(int i=0;i<v[u].size();++i)
{
if(visit[v[u][i]]==0)
dfsSolve(v[u][i],visit,cur);
}
}
int main()
{
int n,m,total=0;
cin>>n>>m;
for(int i=0;i<m;++i)
{
int s,e;
cin>>s>>e;
v[s].push_back(e);
}
for(int i=1;i<=n;++i)
{
int visit[1024]={0};
dfsSolve(i,visit,i);
}
for(int i=1;i<=n;++i)
{
int j;
for(j=1;j<=n;++j)
if(isconnect[i][j]==0)break;
if(j==n+1)++total;
}
cout<<total;
return 0;
}*/
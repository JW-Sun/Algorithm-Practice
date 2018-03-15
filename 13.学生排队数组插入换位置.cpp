#include <iostream>
using namespace std;

int a[1024];
int n,m;

int find(int aa)
{
	int pos;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==aa)
		{
			pos=i;
			break;
		}
	}
	return pos;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int p,q;
		cin>>p>>q;
		int pos=find(p);
		int temp=a[pos];
		if(q>=0)
		{
			for(int j=pos;j<pos+q;j++)
			{
				a[j]=a[j+1];
			}
			a[pos+q]=temp;
		}
		if(q<0)
		{
			for(int j=pos;j>pos+q;j--)
			{
				a[j]=a[j-1];
			}
			a[pos+q]=temp;
		}
	}
	
	
	
	for(int i=1;i<=n;i++)
	{
		if(i!=n)
		{
			cout<<a[i]<<" ";
		}
		else
		{
			cout<<a[i];
		}
	}
	return 0;
}

//http://poj.org/problem?id=2492
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;
int parent[2005]={0};
int color[2005]={0};

int find(int a)
{
	// Using path compression and colouring
	int temp=parent[a];
	if (parent[a]==a)
		return a;
	parent[a]=find(temp);
	color[a]=(color[a]+color[temp])%2;
	return parent[a];
}

void unite(int a,int b)
{
	int x = find(a);
	int y = find(b);
	parent[x]=y;
	color[x]=(color[b]-color[a]+1)%2;
}

int rekt(int a, int b)
{
	int p1 = find(a);
	int p2 = find(b);
	if (p1 == p2)
	{
		if(color[a] == color[b])
			return 0;
		return 1;
	}
	return 2;
}

int main()
{
	int t;
	scanf("%d", &t);
	loop(j,t)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		loop(i,n+1)
		{
			parent[i]=i;
			color[i]=0;
		}
		int x, y;
		int f=0;
		loop(i,m)
		{
			scanf("%d %d", &x, &y);
			if(!f)
			{
				int ans = rekt(x,y);
				if(ans == 0)
					f=1;
				if(ans == 2)
					unite(x,y);
			}
		}
		printf("Scenario #%d:\n", j+1);
		if (f)
			printf("Suspicious bugs found!\n\n");
		else
			printf("No suspicious bugs found!\n\n");
	}
}
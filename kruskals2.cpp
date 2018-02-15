//http://poj.org/problem?id=2395
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
int parent[100001]={0};
int size[100001]={0};

struct edge
{
	int src,des;
	ll dist;
};

bool comp(edge e1, edge e2)
{
	return e1.dist < e2.dist;
}

int find(int a)
{
	while(parent[a]!=a)
		a=parent[a];
	return a;
}

void unite(int a,int b)
{
	int x = find(a);
	int y = find(b);
	if(size[x]<size[y])
	{
		parent[x]=y;
		size[y]+=size[x];
	}
	else
	{
		parent[y]=x;
		size[x]+=size[y];
	}
}

bool same(int a, int b)
{
	return (find(a) == find(b));
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<edge> e;
	loop(i,m)
	{
		edge e1;
		cin >> e1.src >> e1.des >> e1.dist;
		if(e1.dist > 1e9)
			continue;
		e.pb(e1);
	}
	loop(i,n+1)
	{
		parent[i]=i;
		size[i]=1;
	}
	sort(e.begin(),e.end(),comp);
	ll ans=0;
	loop(i,m)
	{
		if(!same(e[i].src,e[i].des))
		{
			unite(e[i].src,e[i].des);
			ans=e[i].dist;
		}
	}
	cout << ans << endl;
}
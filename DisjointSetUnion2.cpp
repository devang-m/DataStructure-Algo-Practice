//http://www.spoj.com/problems/FRNDCIRC/en/
#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;
int parent[200001]={0};
int size[200001]={0};
int ans=0;

int find(int a)
{
	while(parent[a]!=a)
		a=parent[a];
	ans=size[a];
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
		ans=size[y];
	}
	else
	{
		parent[y]=x;
		size[x]+=size[y];
		ans=size[x];
	}
}

bool same(int a, int b)
{
	return (find(a) == find(b));
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,c=1;
		cin >> n;
		map<string,int> m;
		loop(i,2*n+1)
		{
			parent[i]=i;
			size[i]=1;
		}
		loop(i,n)
		{
			string s1,s2;
			cin >> s1 >> s2;
			if(m.count(s1)==0)
				m[s1]=c++;
			if(m.count(s2)==0)
				m[s2]=c++;
			int x=m[s1];
			int y=m[s2];
			if(!same(x,y))
			{
				unite(x,y);
			}
			cout << ans << endl;
		}
	}
}
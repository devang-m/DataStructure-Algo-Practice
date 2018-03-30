//https://www.codechef.com/INOIPRAC/problems/INOI1601
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, ll> ipair;
bool visited[100005]={0};
ll ans = -INF;
vector<ipair> G[100005];

// The ipair, the cost till now, current pos
void DFS(ipair a, ll cost, int b)
{
	visited[a.first]=true;
	//cout << cost << endl;
	ans = max(ans,cost-a.second);
	loop(i,0,G[a.first].size())
	{
		if(visited[G[a.first][i].first]==false)
			DFS(G[a.first][i],max(a.second,cost),a.first);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> sal;
	loop(i,0,n)
	{
		int a;
		scanf("%d", &a);
		sal.pb(a);
	}
	loop(i,0,n)
	{
		int b;
		scanf("%d", &b);
		if(b==-1)
		{
			// Node it is going to and the cost
			G[0].pb(mp(i+1,sal[i]));
		}
		else
		{
			G[b].pb(mp(i+1,sal[i]));
		}
	}
	DFS(G[0][0],-INF,0);
	printf("%lld\n", ans);
}
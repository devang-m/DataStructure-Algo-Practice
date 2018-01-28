//https://vjudge.net/contest/209520#problem/G
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
using namespace std;

vector<int> A[101];
int visited[101]={0};
vector<int> ans;

void dfs(int x)
{
	if(visited[x]==2)
		return;
	visited[x]=1;
	loop(i,A[x].size())
		dfs(A[x][i]);
	visited[x]=2;
	ans.pb(x);
}

int main()
{
	int n,m;
	while(true)
	{
		loop(i,101)
		{
			A[i].clear();
			visited[i]=0;
		}
		ans.clear();

		cin >> n >> m;
		if(n==0 && m==0)
			break;
		while(m--)
		{
			int a,b;
			cin >> a >> b;
			A[a].pb(b);
		}
		loop(i,n)
		{
			if(visited[i+1]==0)
				dfs(i+1);
		}
		for(int i=ans.size()-1;i>=0;i--)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
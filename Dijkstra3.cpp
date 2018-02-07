//http://poj.org/problem?id=1847
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

int main()
{
	int n,x,y;
	cin >> n >> x >> y;
	vector< ipair > A[n+1];
	priority_queue< ipair, vector <ipair> , greater<ipair> > p;
	loop(i,n)
	{
		int a,m;
		cin >> m;
		loop(j,m)
		{
			cin >> a;
			if(j==0)
				A[i+1].pb(make_pair(a,0));
			else
				A[i+1].pb(make_pair(a,1));
		}
	}
	vector<int> dist(101, INF);
	dist[x]=0;
	p.push(make_pair(0,x));
	while(!p.empty())
	{
		int x = p.top().second;
		p.pop();
		for(int i = 0;i<A[x].size();i++)
		{
			int node = A[x][i].first;
			int weight = A[x][i].second;
			if(dist[node] > dist[x] + weight)
			{
				dist[node]= dist[x]+weight;
				p.push(make_pair(dist[x]+weight,node));
			}
		}
	}
	if(dist[y]==INF)
		cout << "-1\n";
	else
		cout << dist[y] << endl;
}
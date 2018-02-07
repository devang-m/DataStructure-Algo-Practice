//http://poj.org/problem?id=2387
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
	int t,n;
	cin >> t >> n;
	vector< ipair > A[1001];
	priority_queue< ipair, vector <ipair> , greater<ipair> > p;
	while(t--)
	{
		int a,b,d;
		cin >> a >> b >> d;
		A[a].pb(make_pair(b,d));
		A[b].pb(make_pair(a,d));
	}
	vector<int> dist(1001, INF);
	dist[1]=0;
	p.push(make_pair(0,1));
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
	cout << dist[n] << endl;
}



	
//http://codeforces.com/problemset/problem/20/C
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define INF 1e15
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

int main()
{
	int m,n;
	cin >> n >> m;
	vector< ipair > A[n+1];
	priority_queue< ipair, vector <ipair> , greater<ipair> > p;
	while(m--)
	{
		int a,b,d;
		cin >> a >> b >> d;
		A[a].pb(make_pair(b,d));
		A[b].pb(make_pair(a,d));
	}
	vector<ll> dist(n+1, INF);
	vector<int> prev(n+1,-1);
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
				prev[node]=x;
				dist[node]= dist[x]+weight;
				p.push(make_pair(dist[x]+weight,node));
			}
		}
	}
	//cout << dist[n] << endl;
	stack <int> s;
	s.push(n);
	int next = n,flag=0;
	while(true)
	{
		if(next==1)
			break;
		if(prev[next] == -1)
		{
			flag=1;
			break;
		}
		s.push(prev[next]);
		next = prev[next];
	}
	if(flag==1)
	{
		cout << "-1\n";
	}
	else
	{
		int size = s.size();
		for(int i=0;i<size;i++)
		{
			int ans = s.top();
			s.pop();
			cout << ans << " ";
		}
		cout << endl;
	}
}



	
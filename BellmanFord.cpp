//http://poj.org/problem?id=3259
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

struct edge
{
	int src,des,dist;
};

vector<edge> A;
int n,m,w;
bool flag=false;
int d[600];

void bellman()
{
	loop(i,n+1)
		d[i]=1e7;
	d[1]=0;
	loop(i,n-1)
	{
		loop(j,2*m+w)
		{
			d[A[j].des]=min(d[A[j].des],d[A[j].src]+A[j].dist);
		}
	}
	loop(j,2*m+w)
	{
		if(d[A[j].des] > d[A[j].src]+A[j].dist)
		{
			flag=true;
			break;
		}
	}
}

int main()
{
	int f;
	cin >> f;
	while(f--)
	{
		A.clear();
		flag=false;
		cin >> n >> m >> w;
		loop(i,m)
		{
			edge e,e1;
			cin >> e.src >> e.des >> e.dist;
			e1.src=e.des;
			e1.des=e.src;
			e1.dist=e.dist;
			A.pb(e);
			A.pb(e1);
		}
		loop(i,w)
		{
			edge e;
			cin >> e.src >> e.des >> e.dist;
			e.dist=e.dist*-1;
		//	cout <<  e.src << e.des << e.dist;
			A.pb(e);
		}
		bellman();
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

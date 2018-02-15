//http://poj.org/problem?id=2031
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <iomanip> 
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;
typedef pair<double, double> dpair;

struct point
{
	double x,y,z,r;
}A[100];

int main()
{
	while(true)
	{
		int n;
		cin >> n;
		if(n==0)
			break;
		loop(i,n)
		{
			A[i].x=0;
			A[i].y=0;
			A[i].z=0;
			A[i].r=0;
		}
		int visited[101]={0};
		double d[101][101]={{0}};
		loop(i,n)
		{
			cin >> A[i].x >> A[i].y >> A[i].z >> A[i].r;
			loop(j,i)
			{
				double dist = sqrt(pow((A[i].x-A[j].x),2) + pow((A[i].y-A[j].y),2) + pow((A[i].z-A[j].z),2));
				if((A[i].r+A[j].r) >= dist)
				{
					d[i][j]=0;
					d[j][i]=0;
				}
				else
				{
					d[i][j]=dist-A[i].r-A[j].r;
					d[j][i]=d[i][j];
				}
			}
		}
		/*
		loop(i,n)
			loop(j,n)
				cout << d[i][j] << " ";
				*/
		priority_queue< dpair, vector <dpair> , greater<dpair> > p;
		p.push(mp(0,0));
		double ans=0.0;
		while(!p.empty())
		{
			int v = p.top().second;
			double dis = p.top().first;
			p.pop();
			if(!visited[v])
			{
				ans+=dis;
				visited[v]=true;
				loop(i,n)
				{
					p.push(mp(d[v][i],i));
				}
			}
		}
		cout << fixed << setprecision(3) << ans << endl;
	}
}
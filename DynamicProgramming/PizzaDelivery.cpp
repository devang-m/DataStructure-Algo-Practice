//https://www.codechef.com/problems/DBOY

/*
Similar to Knapsack problem.
*/

#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int> > iipair;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int dist[n], cap[n];
		int DP[1005]; // DP[i] stores minimum number of fuel recharges to travel a distance i
		loop(i,0,1005)
			DP[i]=INF;
		loop(i,0,n)
		{
			int a;
			cin >> a;
			dist[i]=2*a;
		}
		loop(i,0,n)
		{
			cin >> cap[i];
			DP[cap[i]]=1;
		}
		DP[0]=1;
		// Need to fill everyspot
		loop(i,0,n)
		{
			loop(j,0,1000)
			{
				if(j+cap[i]>1000)
					break;
				if(DP[j]!=INF)
					DP[j+cap[i]]=min(DP[j+cap[i]], DP[j]+1);
			}
		}
		//cout << DP[2] << DP[4] << DP[6] << DP[8];
		int ans = 0;
		loop(i,0,n)
		{
			ans += DP[dist[i]];
		}
		cout << ans << endl;
	}
}
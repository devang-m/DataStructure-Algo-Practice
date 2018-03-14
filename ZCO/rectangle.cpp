//https://www.codechef.com/ZCOPRAC/problems/ZCO15004
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

int main()
{
	int n,x,y;
	cin >> n;
	int A[100001];
	loop(i,0,100001)
		A[i]=INF;
	loop(i,0,n)
	{
		cin >> x >> y;
		A[x]=min(A[x],y);
	}
	int ans=0;
	loop(i,1,501)
	{
		int width=0,c=0;
		loop(j,1,100000)
		{
			if(A[j]>=i)
				c++;
			else
				c=0;
			width=max(width,c);
		}
		ans = max(ans,(width+1)*i);
	}
	cout << ans << endl;
}

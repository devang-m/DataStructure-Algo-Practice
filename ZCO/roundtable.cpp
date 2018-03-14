//https://www.codechef.com/ZCOPRAC/problems/ZCO12004
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
	int n,f=0;
	cin >> n;
	vector<int> A;
	int DP[n],DP1[n];
	loop(i,0,n)
	{
		int a;
		cin >> a;
		A.pb(a);
		DP[i]=INF;
		DP1[i]=INF;
	}
	if(n==1)
	{
		cout << A[0] << endl;
		f=1;
	}
	if(n==2)
	{
		cout << min(A[0],A[1]) << endl;
		f=1;
	}
	if(!f)
	{
		DP[0]=A[0];
		DP1[0]=A[n-1]+A[0];
		DP[1]=A[0]+A[1];
		DP1[1]=A[1]+A[n-1];
		loop(i,2,n)
		{
			DP[i]=min(DP[i-2]+A[i],DP[i-1]+A[i]);
			DP1[i]=min(DP1[i-2]+A[i],DP1[i-1]+A[i]);
		}
	}
	cout << min(min(DP[n-1],DP[n-2]),min(DP1[n-2],DP1[n-3])) << endl;
}
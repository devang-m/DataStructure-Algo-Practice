//https://www.codechef.com/ZCOPRAC/problems/ZCO13003
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
	int DP[n];
	loop(i,0,n)
	{
		int a;
		cin >> a;
		A.pb(a);
		DP[i]=INF;
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
		DP[1]=A[1];
		DP[2]=A[2];
		loop(i,3,n)
		{
			DP[i]=min(DP[i-3],min(DP[i-2],DP[i-1]))+A[i];
		}
	}
	cout << min(DP[n-3],min(DP[n-2],DP[n-1])) << endl;
}
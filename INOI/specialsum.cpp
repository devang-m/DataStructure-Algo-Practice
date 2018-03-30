//https://www.codechef.com/INOIPRAC/problems/INOI1501
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
	// Find max sum of B till i
	int n;
	scanf("%d", &n);
	vector<ll> A,B;
	loop(i,0,n)
	{
		ll a;
		scanf("%lld", &a);
		A.pb(a);
	}
	loop(i,0,n)
	{
		ll a;
		scanf("%lld", &a);
		B.pb(a);
	}
	ll sum[1000005];
	loop(i,0,n)
	{
		sum[i]=-INF;
	}
	ll ansf=max(max(A[0],A[1]),A[0]+A[1]);
	// Sum[i] stores best possible special sum till i+1 excluding it
	sum[1]=A[0]+B[1];
	loop(i,2,n)
	{
		sum[i]=max(sum[i-1],A[i-1])+B[i];
		ansf=max(A[i],max(ansf,sum[i]-B[i]+A[i]));
	}
	//cout << ansf << endl;
	
	ll sumb[n];	
	ll best=A[n-1];
	sumb[n-1]=B[n-1];
	for(int i=n-2;i>=0;i--)
	{
		sumb[i]=0;
		sumb[i]=sumb[i+1]+B[i]; // sum of all elements from n-1 to i
	}
	ll ansb=sumb[0]-sumb[n-2]+best+A[n-2];
	for(int i=n-3;i>=0;i--)
	{
		best = max(best,A[i+1]+sumb[i+2]);
		ansb = max(ansb,best+A[i]+sumb[0]-sumb[i]);
	}
	cout << max(ansb,ansf) << endl;
	
}
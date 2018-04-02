//https://vjudge.net/contest/219295#problemG
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

ll expo(int a, int b)
{
	if(b==1)
		return a;
	if(b%2==0)
	{
		ll c = expo(a,b/2);
		return ((c*c)%MOD);
	}
	else
		return (a*expo(a,b-1))%MOD;
}

int main()
{
	int t,k,n;
	ll inverse[100010]={0};
	inverse[1]=1;
	loop(i,2,100001)
	{
		inverse[i]=expo(i,MOD-2);
	}
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		// Using fermat's little theorem to get the multiplicative inverse
		ll power = expo(2,n);
		ll A[k];
		loop(i,0,k)
			A[i]=0;
		A[0]=1;
		loop(i,1,k)
		{
			A[i]= ((A[i-1]*(n+1-i)%MOD)%MOD * inverse[i])%MOD;
		}
		loop(i,1,k)
		{
			A[i] = (A[i]+A[i-1])%MOD;
		}
		printf("%lld\n", (power+MOD-A[k-1])%MOD);
		//printf("%d\n", A[n][m]);
	}
}
//https://www.codechef.com/INOIPRAC/problems/INOI1502
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
	int n,m;
	scanf("%d %d", &n, &m);
	vector<int> fact;
	int k = sqrt(n);
	loop(i,2,k+1)
	{
		if(n%i==0)
		{
			fact.pb(i);
			if(i!=n/i)
				fact.pb(n/i);
		}
	}
	int A[n+1];
	A[1]=0;
	A[2]=2;
	A[3]=6;
	//cout << -2%6 << endl;
	loop(i,4,n+1)
	{
		A[i]=((A[i-1]*2)%m +2)%m;
	}
	sort(fact.begin(), fact.end());
	loop(i,0,fact.size())
	{
		k = sqrt(fact[i]);
		loop(j,2,k+1)
		{
			if(fact[i]%j==0)
			{
				A[fact[i]]=(A[fact[i]]-A[j]+m)%m;
				if(j!=fact[i]/j)
					A[fact[i]]=(A[fact[i]]-A[fact[i]/j]+m)%m;
			}
		}
		//cout << A[fact[i]] << endl;

	}
	loop(i,0,fact.size())
	{
		//cout << A[n] << endl;
		A[n]=(A[n]-A[fact[i]]+m)%m;
	}
	printf("%d\n", A[n]);
}
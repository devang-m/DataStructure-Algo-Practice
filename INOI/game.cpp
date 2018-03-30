//https://www.codechef.com/INOIPRAC/problems/INOI1301
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
	int n,k;
	scanf("%d %d", &n, &k);
	k--;
	int A[n],DPf[n+2],DPb[n+2];
	loop(i,0,n)
	{
		scanf("%d", &A[i]);
		DPf[i]=0;
		DPb[i]=0;
	}
	DPf[n]=0; DPb[n]=0;
	DPf[n+1]=0; DPb[n+1]=0;
	DPf[k+1]=A[k+1];
	DPf[k+2]=max(A[k+2],A[k+1]+A[k+2]);
	loop(i,k+3,n)
	{
		DPf[i]=max(DPf[i-1],DPf[i-2])+A[i];
	}
	DPb[1]=0;
	DPb[2]=max(A[1],0);
	loop(i,3,n)
	{
		DPb[i]=max(DPb[i-2]+A[i-2], DPb[i-1]+A[i-1]);
	}
	int ans = -1e9;
	loop(i,k,n)
	{
		//cout << DPf[i] << " " << DPb[i] << endl;
		ans = max(ans, DPf[i]+DPb[i]);
	}
	ans+=A[0];
	printf("%d\n", ans);
}
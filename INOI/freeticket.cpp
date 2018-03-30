//https://www.codechef.com/INOIPRAC/problems/INOI1402
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;
int n;

void floydwarshall(int A[240][240])
{
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			loop(k,0,n)
			{
				A[j][k] = min(A[j][k],A[j][i]+A[i][k]);
			}
		}
	}
	int m = 0;
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			if(i==j)
				continue;
			m =  max(m,A[i][j]);			
		}
	}
	printf("%d\n", m);
}

int main()
{
	int p;
	scanf("%d %d", &n, &p);
	int A[240][240];
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			A[i][j]=1e7;
			if(i==j)
				A[i][j]=0;
		}
	}
	loop(i,0,p)
	{
		int a,b,cost;
		scanf("%d %d %d", &a, &b, &cost);
		a--; b--;
		A[a][b]=min(A[a][b],cost);
		A[b][a]=min(A[b][a],cost);
	}
	floydwarshall(A);
}
//https://www.codechef.com/INOIPRAC/problems/INOI1602
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
	int n,s,a;
	scanf("%d %d", &n, &s);
	vector<int> v,b;
	loop(i,0,n)
	{
		scanf("%d", &a);
		v.pb(a);
	}
	loop(i,0,n)
	{
		scanf("%d", &a);
		b.pb(a);
	}
	int A[705][705]={{0}};
	for(int i=n-1;i>=0;i--) // left
	{
		for(int j=n-1;j>=0;j--) // right
		{
			if(i>=j)
				A[i][j]=0;
			else
			{
				for(int k=i;k<=j;k++)
				{
					if(b[i]+s == b[k])
						A[i][j]=max(A[i][j],A[i+1][k-1]+v[i]+v[k]+A[k+1][j]);
				}
			}
			A[i][j]=max(A[i][j],A[i+1][j]);
		}
	}
	/*
	loop(i,0,n)
	{	
		loop(j,0,n)
			cout << A[i][j] << " ";
		cout << endl;
	}
	*/
	printf("%d\n", A[0][n-1]);

}
//https://www.codechef.com/INOIPRAC/problems/INOI1401
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;
ll ans[305][305][305][2]={{{{0}}}};

int main()
{
	int r,c,d;
	scanf("%d %d %d", &r, &c, &d);
	int A[r][c];
	loop(i,0,r)
	{
		loop(j,0,c)
		{
			int a;
			scanf("%d", &a);
			A[i][j]=a;
		}
	}
	// 0 is left, 1 is up, 3rd one shows length of the path from left/up
	// Also d+1 holds the sum
	ans[0][0][0][0]=1;
	// Initialising
	loop(i,0,d)
	{
		if(A[0][i+1]!=0)
			ans[0][i+1][i+1][0]= ans[0][i+1][d+1][0] = 1;
		else
			break;
	}
	loop(i,0,d)
	{
		if(A[i+1][0]!=0)
			ans[i+1][0][i+1][1]=ans[i+1][0][d+1][1]=1;
		else
			break;
	}

	loop(i,1,r)
	{
		loop(j,1,c)
		{
			ll leftsum=0,upsum=0;
			loop(k,1,d+1)
			{
				if(A[i][j]==0)
					continue;
				if(k==1)
				{
					leftsum = ans[i][j][k][0] = ans[i][j-1][d+1][1];
					upsum = ans[i][j][k][1] = ans[i-1][j][d+1][0];
				}
				else
				{
					ans[i][j][k][0] = ans[i][j-1][k-1][0];
					leftsum = (leftsum + ans[i][j][k][0])%20011;
					ans[i][j][k][1] = ans[i-1][j][k-1][1];
					upsum = (upsum + ans[i][j][k][1])%20011;
				}
			}
			ans[i][j][d+1][0]=leftsum;
			ans[i][j][d+1][1]=upsum;
		}
	}
	printf("%lld\n", (ans[r-1][c-1][d+1][0] + ans[r-1][c-1][d+1][1])%20011);

} 

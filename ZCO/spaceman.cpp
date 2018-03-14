//https://www.codechef.com/ZCOPRAC/problems/ZCO13004
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

struct pos
{
	bool safe;
	int val;
};

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	bool A[n][m];
	int DP[n][m];
	loop(i,0,n)
	{
		loop(j,0,m)
		{
			A[i][j]=true;
			DP[i][j]=INF;
		}
	}
	loop(i,0,k)
	{
		int x,y,start,freq;
		cin >> x >> y >> start >> freq;
		x--; y--;
		//A[x][y]=false;
		loop(j,y,m)
		{
			// j+x >= j-y+start
			if((x+y-start>=0) && (x-start+y)%freq == 0)
				A[x][j]=false;
		}
		loop(j,x,n)
		{
			if((x+y-start>=0) && (x-start+y)%freq == 0)
				A[j][y]=false;
		}
		// Check these 2 loops
		loop(j,0,y)
		{
			if((x+(2*j)-y-start>=0) && (x+(2*j)-y-start)%freq == 0)
				A[x][j]=false;
		}
		loop(j,0,x)
		{
			// y+j >= (x-j+start)
			if((y+(2*j)-x-start>=0) && (y+(2*j)-x-start)%freq == 0)
				A[j][y]=false;
		}
	}
	/*
	loop(i,0,n)
	{
		loop(j,0,m)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	*/
	if(A[0][0])
		DP[0][0]=0;
	loop(i,1,n)
	{
		if(A[i][0] && DP[i-1][0]!=INF)
			DP[i][0]=i;
	}
	loop(i,1,m)
	{
		if(A[0][i] && DP[0][i-1]!=INF)
			DP[0][i]=i;
	}
	loop(i,1,n)
	{
		loop(j,1,m)
		{
			if(A[i][j] && DP[i-1][j]!=INF)
				DP[i][j]=i+j;
			if(A[i][j] && DP[i][j-1]!=INF)
				DP[i][j]=i+j;
		}
	}
	/*
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			cout << DP[i][j] << " ";
		}
		cout << endl;
	}
	*/
	if(DP[n-1][m-1]== INF)
		cout << "NO\n";
	else
		cout << "YES\n" << DP[n-1][m-1] << endl; 
	
}
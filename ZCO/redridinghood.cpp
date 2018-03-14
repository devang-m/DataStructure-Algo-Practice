//https://www.codechef.com/ZCOPRAC/problems/ZCO13002
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
	int n,m;
	cin >> n >> m;
	pos A[n][n];
	int DP[n][n];
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			int a;
			cin >> a;
			A[i][j].safe = false;
			A[i][j].val = a;
			DP[i][j]=-INF;
		}
	}
	loop(i,0,m)
	{
		int a,b,s;
		cin >> a >> b >> s;
		a--; b--;
		loop(j,0,min(n,s+1))
		{
			loop(k,j,min(n,s+1))
			{
				if(j+k > s)
					continue;
				if(a-j>=0 && b-k>=0)
					A[a-j][b-k].safe=true;
				if(a-j>=0 && b+k<n)
					A[a-j][b+k].safe=true;
				if(a+j<n && b+k<n)
					A[a+j][b+k].safe=true;
				if(a+j<n && b-k>=0)
					A[a+j][b-k].safe=true;
				if(a-k>=0 && b-j>=0)
					A[a-k][b-j].safe=true;
				if(a-k>=0 && b+j<n)
					A[a-k][b+j].safe=true;
				if(a+k<n && b+j<n)
					A[a+k][b+j].safe=true;
				if(a+k<n && b-j>=0)
					A[a+k][b-j].safe=true;
			}
		}
	}
	/*
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			cout << A[i][j].safe << " ";
		}
		cout << endl;
	}
	*/
	if(A[0][0].safe)
		DP[0][0]=A[0][0].val;
	loop(i,1,n)
	{
		if(A[i][0].safe && DP[i-1][0]!=-INF)
			DP[i][0]=max(DP[i][0], DP[i-1][0]+A[i][0].val);
		if(A[0][i].safe && DP[0][i-1]!=-INF)
			DP[0][i]=max(DP[0][i], DP[0][i-1]+A[0][i].val);
	}
	loop(i,1,n)
	{
		loop(j,1,n)
		{
			if(A[i][j].safe && DP[i-1][j]!=-INF)
				DP[i][j]=max(DP[i][j], DP[i-1][j]+A[i][j].val);
			if(A[i][j].safe && DP[i][j-1]!=-INF)
				DP[i][j]=max(DP[i][j], DP[i][j-1]+A[i][j].val);
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
	if(DP[n-1][n-1]== -INF)
		cout << "NO\n";
	else
		cout << "YES\n" << DP[n-1][n-1] << endl; 
}
//https://www.codechef.com/ZCOPRAC/problems/ZCO15001
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
	int n;
	cin >> n;
	vector<int> v;
	ll A[n][n];
	loop(i,0,n)
	{
		int a;
		cin >> a;
		v.pb(a);
	}
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			if(i==j)
				A[i][j]=1;
			else
				A[i][j]=INF;
		}
	}
	loop(i,1,n)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(v[j]==v[i] && (A[i-1][j+1]==1 || i-j==1))
				A[i][j]=1;
			else
				loop(k,j+1,n)
					A[i][j]=min(A[i][j],A[i][k]+A[k-1][0]);
		}
	}
	/*
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout << A[n-1][0] << endl;

}
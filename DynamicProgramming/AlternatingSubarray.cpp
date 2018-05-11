//https://www.codechef.com/problems/ALTARAY

/*
There's an array A consisting of N non-zero integers A1..N. 
A subarray of A is called alternating if any two adjacent elements in it have different signs (i.e. one of them should be negative and the other should be positive).
For each x from 1 to N, compute the length of the longest alternating subarray
*/

#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int> > iipair;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int A[n],B[n];
		loop(i,0,n)
			cin >> A[i];
		B[n-1]=1;
		for(int i=n-2;i>=0;i--)
		{
			if((A[i]>=0 && A[i+1]>=0) || (A[i]<0 && A[i+1]<0))
				B[i]=1;
			else
				B[i]=B[i+1]+1;
		}
		loop(i,0,n)
			cout << B[i] << " ";
		cout << endl;
	}
}
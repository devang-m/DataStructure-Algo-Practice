//https://www.codechef.com/problems/DELISH

#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int> > iipair;

struct minimax
{
	ll maxleft, maxright, minleft, minright;
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		ll A[n], curr1, curr2;
		minimax DP[n];
		loop(i,0,n)
			cin >> A[i];
		DP[0].minleft = DP[0].maxleft = curr2 = curr1 = A[0];
		DP[n-1].minright = DP[n-1].maxright = A[n-1];
		/*
			DP[i].minleft = minimum subsequence array left of i, including i
			DP[i].maxleft = maximum subsequence array left of i, including i
			DP[i].minright = minimum subsequence array right of i, including i
			DP[i].maxright = maximum subsequence array right of i, including i
			The currs have sums that always include the prev position
		*/

		loop(i,1,n)
		{
			curr1 = min(curr1+A[i],A[i]);
			DP[i].minleft = min(curr1, DP[i-1].minleft);
			curr2 = max(curr2+A[i],A[i]);
			DP[i].maxleft = max(curr2, DP[i-1].maxleft);
		}
		curr1 = curr2 = A[n-1];
		for(int i=n-2;i>=0;i--)
		{
			curr1 = min(curr1+A[i],A[i]);
			DP[i].minright = min(curr1, DP[i+1].minright);
			curr2 = max(curr2+A[i],A[i]);
			DP[i].maxright = max(curr2, DP[i+1].maxright);
		}
		ll ans = abs(DP[0].minleft - DP[1].maxright);
		loop(i,0,n-1)
		{
			ans = max(max(ans,abs(DP[i].minleft-DP[i+1].maxright)),abs(DP[i+1].minright-DP[i].maxleft));
		}
		cout << ans << endl;
	}
}
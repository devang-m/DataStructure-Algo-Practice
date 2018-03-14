//https://www.codechef.com/ZCOPRAC/problems/ZCO15002
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
	cin >> n >> k;
	vector<int> v;
	loop(i,0,n)
	{
		int a;
		cin >> a;
		v.pb(a);
	}
	sort(v.begin(),v.end());
	ll ans=0;
	loop(i,0,n)
	{
		vector<int>::iterator l;
		l = lower_bound(v.begin(),v.end(),v[i]+k);
		ans+=(n-(l-v.begin()));
	}
	cout << ans << endl;
}
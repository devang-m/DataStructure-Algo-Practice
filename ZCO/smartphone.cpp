//https://www.codechef.com/ZCOPRAC/problems/ZCO14003
#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0; i < n; i++)
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
	vector<ll> v;
	loop(i,n)
	{
		ll a;
		cin >> a;
		v.pb(a);
	}
	sort(v.begin(),v.end());
	ll ans = 0,c=1;
	for(int i=v.size()-1;i>=0;i--)
	{
		ans = max(ans,v[i]*c);
		c++;
	}
	cout << ans << endl;
}
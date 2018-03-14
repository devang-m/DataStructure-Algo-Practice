//https://www.codechef.com/ZCOPRAC/problems/ZCO13001
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
	vector<ll> v;
	loop(i,0,n)
	{
		ll a;
		cin >> a;
		v.pb(a);
	}
	sort(v.begin(),v.end());
	ll prev=0,cur=0,ans=0;
	loop(i,1,n)
	{
		cur = (v[i]-v[i-1])*i + prev;
		ans+=cur;
		prev = cur;
	}
	cout << ans << endl;
}
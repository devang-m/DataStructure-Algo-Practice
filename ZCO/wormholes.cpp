//https://www.codechef.com/ZCOPRAC/problems/ZCO12002
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

bool comp(ipair a, ipair b)
{
	if(a.first == b.first)
		return a.second<=b.second;
	return a.first<b.first;
}

int main()
{
	int n,x,y,a,b;
	cin >> n >> x >> y;
	vector<ipair> v;
	loop(i,0,n)
	{
		cin >> a >> b;
		v.pb(mp(a,b));
	}
	vector<int> start;
	vector<int> end;
	loop(i,0,x)
	{
		cin >> a;
		start.pb(a);
	}
	loop(i,0,y)
	{
		cin >> a;
		end.pb(a);
	}
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());
	sort(v.begin(), v.end(), comp);
	int ans = INF;
	loop(i,0,n)
	{
		int s,e;
		vector<int>:: iterator itr1,itr2;
		itr1 = upper_bound(start.begin(), start.end(), v[i].first);
		if((itr1 - start.begin()) == 0)
			continue;
		itr1--;
		s = *(itr1);
		itr2 = lower_bound(end.begin(), end.end(), v[i].second);
		if(itr2 == end.end())
			continue;
		e = *(itr2);
		ans = min(ans, e-s+1);
	}
	cout << ans << endl;
}
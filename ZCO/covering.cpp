//https://www.codechef.com/ZCOPRAC/problems/ZCO15003
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
	int n;
	cin >> n;
	vector<ipair> v;
	loop(i,0,n)
	{
		int a,b;
		cin >> a >> b;
		v.pb(mp(a,b));
	}
	sort(v.begin(), v.end(),comp);
	priority_queue<int, vector<int>, greater<int> > pq;
	int p1=0,ans=0;
//	loop(i,0,n)
//		cout << v[i].first << " " << v[i].second << endl;
	pq.push(v[0].second);
	while(p1!=n)
	{
		while(v[p1].first <= pq.top() && p1!=n)
		{
			//cout << pq.top() << endl;
			p1++;
			pq.push(v[p1].second);

		}
		ans++;
		pq = priority_queue<int, vector<int>, greater<int> >();
		pq.push(v[p1].second);
	}
	cout << ans++ << endl;
}
//https://www.codechef.com/INOIPRAC/problems/INOI1201
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
	return a.second > b.second;
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<ipair> v;
	loop(i,0,n)
	{
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		v.pb(mp(a,b+c));
	}
	sort(v.begin(), v.end(),comp);
	int ans=0,f=0;
	loop(i,0,n)
	{	
		ans = max(ans,f+v[i].first+v[i].second);
		f+=v[i].first;
	}
	printf("%d\n", ans);
}
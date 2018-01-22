//https://vjudge.net/contest/208188#problemC
#include <iostream>
#include <vector>
#include <cmath>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<pair<int,int> > v;
	loop(i,n)
	{
		pair<int,int> p;
		int a,b;
		cin >> a >> b;
		p = make_pair(a,b);
		v.pb(p);
	}
	int A[12882]={0};
	loop(i,n)
	{
		for(int j=m;j>=0+v[i].first;j--)
		{
			A[j]=max(A[j],A[j-v[i].first]+v[i].second);
		}
	}
	int ans=0;
	loop(i,m+1)
	{
		ans=max(ans,A[i]);
	}
	cout << ans << endl;
}
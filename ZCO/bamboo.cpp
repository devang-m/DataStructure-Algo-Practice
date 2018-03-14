//https://www.codechef.com/ZCOPRAC/problems/ZCO16002
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
	bool A[100000001];
	memset(A,0,sizeof(A));
	loop(i,0,n)
	{
		int a;
		cin >> a;
		v.pb(a);
		A[a]=true;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	loop(i,0,n)
	{
		loop(j,i+1,n)
		{
			int diff = v[j]-v[i];
			int x = v[j]+diff;;
			int c = 2;
			while(A[x]==true)
			{
				c++;
				x+=diff;
			}
			if(c > ans)
				ans = c;	
			//cout << ans << " ";
			//cout << v[i] << " " << v[j] << " " << diff << " " << mod << " " << m[diff][mod] << endl;
		}
	}
	cout << ans << endl;
}
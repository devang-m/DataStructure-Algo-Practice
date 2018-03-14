//https://www.codechef.com/ZCOPRAC/problems/ZCO14001
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
	int n,m;
	cin >> n >> m;
	vector<int> v;
	loop(i,n)
	{
		int a;
		cin >> a;
		v.pb(a);
	}
	int pos=0,hold=0;
	while(true)
	{
		int a;
		cin >> a;
		if (a==0)
			break;
		if(a==1 && pos!=0)
			pos--;
		if(a==2 && pos!=n-1)
			pos++;
		if(a==3)
		{
			if(v[pos]==0 || hold==1)
				continue;
			else
			{
				v[pos]--;
				hold=1;
			}
		}
		if(a==4)
		{
			if(hold==0 || v[pos]==m)
				continue;
			else
			{
				v[pos]++;
				hold=0;
			}
		}
	}
	loop(i,n)
		cout << v[i] << " ";
	cout << endl;
}
//https://www.codechef.com/ZCOPRAC/problems/ZCO12001
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
	loop(i,0,n)
	{
		int a;
		cin >> a;
		v.pb(a);
	}
	int val=0,depth=0,pos=0,max1=0,max2=0,c=0;
	loop(i,0,n)
	{
		if(v[i]==1)
			val++;
		else
			val--;
		if(val>depth)
		{
			depth=val;
			pos=i+1;
		}
		if(val!=0)
			c++;
		else
		{
			if(c+1 > max1)
			{
				max1=c+1;
				max2=i+2-max1;
			}
			c=0;
		}
	}
	cout << depth << " " << pos << " " << max1 << " " << max2 << endl;
}
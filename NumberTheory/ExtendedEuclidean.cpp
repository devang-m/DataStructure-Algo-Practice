//https://vjudge.net/contest/219295#problemD
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

bool f;

// Calculating the a(Non negative number for a) and b values of given numbers x and y such that ax+by=1.
void gcd(ll a, ll b, ll &x, ll &y)
{
	if(b==1)
	{
		f=true;
		x=0;
		y=1;
		return;
	}
	if(a%b==0)
	{
		f=false;
		return;
	}
	gcd(b,a%b,x,y);
	if(f)
	{
		ll temp = x;
		x = y;
		y = (-y)*(a/b) + temp;
	}

}

int main()
{
	ll a,b;
	while(scanf("%lld %lld", &a, &b)!=EOF)
	{
		ll x1=0,y1=0;
		f=false;
		gcd(a,b,x1,y1);
		if(f)
		{
			if(x1>=0)
				cout << x1 << " " << y1 << endl;
			else
				cout << x1+b << " " << y1-a << endl;
		}
		else
			cout << "sorry\n";
	}
}

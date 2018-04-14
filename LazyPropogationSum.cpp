//http://poj.org/problem?id=3468
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
#define INF 1e10
#define MOD 1007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

vector<ll> input;
ll sum[400000]={0}, lazy[400000]={0};

void update(int qlow, int qhigh, int low, int high, int pos, int value)
{
	if(lazy[pos]!=0)
	{
		sum[pos]+=(lazy[pos]*(high-low+1));
		if(low!=high)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(qlow<=low && qhigh>=high)
	{
		sum[pos]+=(value*(high-low+1));
		if(low!=high)
		{
			lazy[2*pos+1]+=value;
			lazy[2*pos+2]+=value;
		}
		return;
	}
	if(qhigh<low || qlow>high)
		return;
	int mid = (low+high)/2;
	update(qlow,qhigh,low,mid,2*pos+1,value);
	update(qlow,qhigh,mid+1,high,2*pos+2,value);
	sum[pos]=sum[2*pos+1]+sum[2*pos+2];
}

ll query(int qlow, int qhigh, int low, int high, int pos)
{
	if(lazy[pos]!=0)
	{
		sum[pos]+=(lazy[pos]*(high-low+1));
		if(low!=high)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(qhigh<low || qlow>high)
		return 0;
	if(qlow<=low && qhigh>=high)
		return sum[pos];
	int mid = (low+high)/2;
	ll ans1 = query(qlow,qhigh,low,mid,2*pos+1);
	ll ans2 = query(qlow,qhigh,mid+1,high,2*pos+2);
	return ans1+ans2;
}

void buildTree(int low, int high, int pos)
{
	if(low==high)
	{
		sum[pos]=input[low];
		return;
	}
	int mid = (low+high)/2;
	buildTree(low,mid,2*pos+1);
	buildTree(mid+1,high,2*pos+2);
	sum[pos] = sum[2*pos+1]+sum[2*pos+2];
}

int main()
{
	ll n,a,q,b,c;
	char quer;
	scanf("%lld %lld", &n, &q);
	loop(i,0,n)
	{
		scanf("%lld", &a);
		input.pb(a);
	}
	buildTree(0,n-1,0);
	loop(i,0,q)
	{
		scanf("%c", &quer);
		scanf("%c", &quer);
		if(quer=='Q')
		{
			//cout << "LOL";
			scanf("%lld %lld", &a, &b);
			printf("%lld\n", query(a-1,b-1,0,n-1,0));
		}
		else
		{
			scanf("%lld %lld %lld", &a, &b, &c);
			update(a-1,b-1,0,n-1,0,c);
		}
	}
}
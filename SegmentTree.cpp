//http://www.spoj.com/problems/GSS3/en/
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

vector<int> input;

struct node
{
	ll sum,prefix,suffix,best;
};

node A[200000];

void update(int Apos, int value, int low, int high, int pos)
{
	if(low==high && low==Apos)
	{
		A[pos].sum=value;
		A[pos].prefix=value;
		A[pos].suffix=value;
		A[pos].best=value;
		return;
	}
	int mid = (low+high)/2;
	if(Apos>=low && Apos<=mid)
		update(Apos,value,low,mid,2*pos+1);
	else
		update(Apos,value,mid+1,high,2*pos+2);
	A[pos].sum = A[2*pos+1].sum+A[2*pos+2].sum;
	A[pos].prefix = max(A[2*pos+1].prefix,A[2*pos+1].sum+A[2*pos+2].prefix);
	A[pos].suffix = max(A[2*pos+2].suffix,A[2*pos+2].sum+A[2*pos+1].suffix);
	A[pos].best = max(A[2*pos+1].suffix+A[2*pos+2].prefix,max(A[2*pos+1].best,A[2*pos+2].best));
}

node query(int qlow, int qhigh, int low, int high, int pos)
{
	node inf;
	inf.sum = inf.prefix = inf.suffix = inf.best = -INF;
	if(qhigh<low || qlow>high)
		return inf;
	if(qlow<=low && qhigh>=high)
		return A[pos];
	int mid = (low+high)/2;
	node ans1 = query(qlow,qhigh,low,mid,2*pos+1);
	node ans2 = query(qlow,qhigh,mid+1,high,2*pos+2);
	node ans;
	ans.sum = ans1.sum+ans2.sum;
	ans.prefix = max(ans1.prefix,ans1.sum+ans2.prefix);
	ans.suffix = max(ans2.suffix,ans2.sum+ans1.suffix);
	ans.best = max(ans1.suffix+ans2.prefix,max(ans1.best,ans2.best));
	//cout << pos << " " << ans.best << endl;
	return ans;
}

void buildTree(int low, int high, int pos)
{
	if(low==high)
	{
		A[pos].sum=input[low];
		A[pos].prefix=input[low];
		A[pos].suffix=input[low];
		A[pos].best=input[low];
		return;
	}
	int mid = (low+high)/2;
	buildTree(low,mid,2*pos+1);
	buildTree(mid+1,high,2*pos+2);
	A[pos].sum = A[2*pos+1].sum+A[2*pos+2].sum;
	A[pos].prefix = max(A[2*pos+1].prefix,A[2*pos+1].sum+A[2*pos+2].prefix);
	A[pos].suffix = max(A[2*pos+2].suffix,A[2*pos+2].sum+A[2*pos+1].suffix);
	A[pos].best = max(A[2*pos+1].suffix+A[2*pos+2].prefix,max(A[2*pos+1].best,A[2*pos+2].best));
}

int main()
{
	int n,a,m,q,b;
	scanf("%d", &n);
	loop(i,0,n)
	{
		scanf("%d", &a);
		input.pb(a);
	}
	loop(i,0,200000)
	{
		A[i].sum=-INF;
		A[i].prefix=-INF;
		A[i].suffix=-INF;
		A[i].best=-INF;
	}
	buildTree(0,n-1,0);
	scanf("%d", &m);
	loop(i,0,m)
	{
		scanf("%d %d %d", &q, &a, &b);
		if(q==1)
		{
			printf("%lld\n", query(a-1,b-1,0,n-1,0).best);
		}
		else
		{
			update(a-1,b,0,n-1,0);
			//loop(j,0,7)
			//	cout << A[2].sum << " " << A[2].prefix << " " << A[2].suffix << " " << A[2].best << endl;
		}
	}
}


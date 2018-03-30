//https://www.codechef.com/INOIPRAC/problems/INOI1202
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

// Basically have a left and right for everyone and then take the best. Pre compute left and right
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v,ans;
	loop(i,0,n)
	{
		int a;
		scanf("%d", &a);
		v.pb(a);
	}
	int left[n],right[n];
	left[0]=0;
	loop(i,1,n)
	{
		left[i]=max(left[i-1]-1,v[i-1]+n-1); // left[i] does not include ith position
	}
	right[n-1]=0;
	for(int i=n-2;i>=0;i--)
	{
		right[i]=max(v[i+1]+1,right[i+1]+1); // right[i] does not include ith position
	}
	// left[i] and right[i] store max to the left and right of i when n is at i
	for(int i=n-1;i>=0;i--)
	{
		//cout << left[i] << " " << right[i] << endl;
		printf("%d ", max(max(left[i],right[i]),v[i]+n));
	}
	printf("\n");
}

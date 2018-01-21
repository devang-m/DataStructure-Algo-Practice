//https://vjudge.net/contest/208188#problem
// Finding the length of the Longest Increasing Subsequence in an array in O(n log n)
#include <iostream>
#include <vector>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
	int n,k;
	scanf("%d", &n);
	vector<int> v;
	loop(i,n)
	{
		scanf("%d",&k);
		v.pb(k);
	}
	vector<int> ans;
	ans.pb(1000001);
	loop(i,n)
	{
		int len = ans.size();
		if(v[i]<ans[0])
			ans[0]=v[i];
		else if(v[i]>ans[len-1])
			ans.pb(v[i]);
		
		else
		{
			int l,r;
			l=0;
			r=ans.size()-1;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(v[i]>ans[mid])
					l=mid+1;
				else
					r=mid;
			}
			ans[r]=v[i];
		}	
	}
	cout << ans.size() << endl;
}
//http://poj.org/problem?id=2533
// Finding the length of the Longest Increasing Subsequence in an array in O(n log n)
#include <iostream>
#include <vector>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
using namespace std;

/*
In general, we have set of active lists of varying length. We are adding an element v[i] to these lists. 
We scan the lists (for end elements) in decreasing order of their length. We will verify the end elements of all the lists to find a list whose end element is smaller than v[i]. 
1. If v[i] is smallest among all end candidates of active lists, we will start new active list of length 1
2. If v[i] is largest among all end candidates of active lists, we will clone the largest active list, and extend it by v[i].
3. If v[i] is in between, we will find a list with largest end element that is smaller than v[i]. 
  Clone and extend this list by v[i]. We will discard all other lists of same length as that of this modified list.

  Source of description : Geeks for Geeks
  */
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
		// Using binary search to clone and extend the active list in ans, by v[i]
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

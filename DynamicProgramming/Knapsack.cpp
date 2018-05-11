//http://poj.org/problem?id=3624

/* Simple Knapsack Problem
Bessie has gone to the mall's jewelry store and spies a charm bracelet. 
She'd like to fill it with the best charms possible from the N (1 ≤ N ≤ 3,402) available charms. 
Each charm i in the supplied list has a weight Wi (1 ≤ Wi ≤ 400), a 'desirability' factor Di (1 ≤ Di ≤ 100), and can be used at most once. 
Bessie can only support a charm bracelet whose weight is no more than M (1 ≤ M ≤ 12,880).

Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.
*/
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
	int A[12882]={0}; // A[i] to store the maximum sum of ratings for a particular weight i
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
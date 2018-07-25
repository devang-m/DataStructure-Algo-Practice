//http://poj.org/problem?id=3624

/* Simple Knapsack Problem
Bessie has gone to the mall's jewelry store and spies a charm bracelet. 
She'd like to fill it with the best charms possible from the N (1 ≤ N ≤ 3,402) available charms. 
Each charm i in the supplied list has a weight Wi (1 ≤ Wi ≤ 400), a 'desirability' factor Di (1 ≤ Di ≤ 100), and can be used at most once. 
Bessie can only support a charm bracelet whose weight is no more than M (1 ≤ M ≤ 12,880).

Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.
*/
#include <iostream>
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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long n, m;
	cin >> n >> m;
	int w[n], d[n];
	loop(i,0,n)
		cin >> w[i] >> d[i];
	int total[m+1];
	loop(i,0,m+1)
		total[i] = 0;
	loop(i,0,n)
	{
		for(int j = m; j>= w[i]; j--)
		{
			if(total[j-w[i]]!=0 || j-w[i]==0)
				total[j] = max(total[j], total[j-w[i]]+d[i]);
		}
	}
	int ans = 0;
	loop(i,0,m+1)
	{
		//cout << total[i] << endl;
		ans = max(ans,total[i]);
	}
	cout << ans << endl;
}

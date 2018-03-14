//https://www.codechef.com/ZCOPRAC/problems/ZCO12003
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
	int A[n];
	loop(i,0,n)
		cin >> A[i];
	//a for () b for []
	stack<int> a,b;
	int maxa=0,maxb=0,alt=0,ans=0;
	loop(i,0,n)
	{
		if(A[i]==1)
		{
			
			if(a.empty() && b.empty())
				alt = 1;
			else if (b.empty());
			else if (a.empty())
				alt++;
			else if(a.top() < b.top())
				alt++;
				
			a.push(i);
		}
		if(A[i]==2)
		{
			int x = a.top();
			maxa = max(maxa,i-x+1);
			a.pop();
			if(a.empty() && b.empty())
				alt = 0;
			else if (b.empty());
			else if (a.empty())
				alt--;
			else if(a.top() < b.top())
				alt--;
				
		}
		if(A[i]==3)
		{
			if(a.empty() && b.empty())
				alt = 1;
			else if (a.empty());
			else if (b.empty())
				alt++;
			else if(a.top() > b.top())
				alt++;
			b.push(i);
		}
		if(A[i]==4)
		{
			int x = b.top();
			maxb = max(maxb,i-x+1);
			b.pop();
			if(a.empty() && b.empty())
				alt = 0;
			else if (a.empty());
			else if (b.empty())
				alt--;
			else if(a.top() > b.top())
				alt--;
		}
		ans = max(ans,alt);
	}
	cout << ans << " " << maxa << " " << maxb << endl;
}
//http://www.spoj.com/problems/RPLN/
#include <bits/stdc++.h>
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;
int main()
{
	int t,n,q,start,end;
	scanf("%d", &t);
	loop(k,t)
	{
		scanf("%d %d", &n, &q);
		int A[n];
		loop(i,n)
		{
			scanf("%d", &A[i]);
		}
		int table[n][18];
		loop(i,n)
		{
			table[i][0]=A[i];
		}
		for(int i=1;i<18;i++)
		{
			for(int j=0;j<=n-pow(2,i);j++)
			{
				table[j][i]=min(table[j][i-1],table[j+(int)pow(2,i-1)][i-1]);
			}	
		}
		printf("Scenario #%d:\n",k+1);
		while(q--)
		{
			scanf("%d %d", &start, &end);
			start--;
			end--;
			int twopow = floor(log(end-start+1)/log(2));
			if(pow(2,twopow)>(end-start+1)) // Hack to ensure no precision loss
				twopow/=2;
			int ans = min(table[start][twopow],table[end-(int)pow(2,twopow)+1][twopow]);
			printf("%d\n", ans);
		}
	}
}
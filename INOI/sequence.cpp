//https://www.codechef.com/INOIPRAC/problems/INOI1302
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

void floydwarshall(int F[300][300],int n)
{
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			loop(k,0,n)
			{
				if(F[j][i]==1 && F[i][k]==1)
					F[j][k]=1;
			}
		}
	}
	int sum=0;
	loop(i,0,n)
	{
		if(F[0][i]==1)
		{
			sum++;
			//cout << i << endl;
		}
	}
	printf("%d\n", sum);
}

int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	vector<int> A[n];
	loop(i,0,n)
	{
		int num;
		scanf("%d", &num);
		loop(j,0,num)
		{
			int a;
			scanf("%d", &a);
			A[i].pb(a);
		}
		sort(A[i].begin(), A[i].end());
	}
	/*
	loop(i,0,n)
	{
		loop(j,0,A[i].size())
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int F[300][300];
	loop(i,0,n)
	{
		loop(j,0,n)
		{
			F[i][j]=0;
			if(i==j)
				F[i][j]=1;
		}
	}
	loop(i,0,n)
	{
		loop(j,i+1,n)
		{
			vector<int> common_data;
			set_intersection(A[i].begin(),A[i].end(),A[j].begin(),A[j].end(), back_inserter(common_data));
			if(common_data.size() >= k)
			{
				F[i][j]=1;
				F[j][i]=1;
			//	cout << i << " " << j << endl;
			}
		}
	}
	floydwarshall(F,n);
}

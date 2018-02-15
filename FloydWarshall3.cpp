//http://poj.org/problem?id=1975
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;
int n;
int A[101][101];

void floydwarshall()
{
	loop(i,n)
	{
		loop(j,n)
		{
			loop(k,n)
			{
				if(A[j][i]==1 && A[i][k]==1)
				{
					A[j][k]=1;
					//cout << "LOL";
				}
				if(A[j][i]==-1 && A[i][k]==-1)
					A[j][k]=-1;
			}
		}
	}
} 

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int m;
		cin >> n >> m;
		int median = (n+1)/2;
		loop(i,101)
			loop(j,101)
				A[i][j]=0;
		loop(i,m)
		{
			int a,b;
			cin >> a >> b;
			A[a-1][b-1]=1;
			A[b-1][a-1]=-1;
		}
		floydwarshall();
		int sum0=0,sum1=0,count=0;
		loop(i,n)
		{
			sum0=0;sum1=0;
			loop(j,n)
			{
				if(A[i][j]==1)
					sum1++;
				if(A[i][j]==-1)
					sum0++;
			}
			if(sum1>= median || sum0>=median)
				count++;
		}
		cout << count << "\n";
	}
}

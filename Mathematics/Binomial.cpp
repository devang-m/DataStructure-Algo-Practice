//https://vjudge.net/contest/219295#problemB
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
#define INF 2147483647
#define MOD 1007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;
int A[2005][2005]={{0}};

int main()
{
	int t,m,n;
	A[1][0]=1;
	A[1][1]=1;
	loop(i,2,2001)
	{
		A[i][0]=1;
		A[i][i]=1;
		loop(j,1,i)
		{
			A[i][j]=(A[i-1][j]+A[i-1][j-1])%MOD;
		}
	}
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &m, &n);
		printf("%d\n", A[n][m]);
	}
}
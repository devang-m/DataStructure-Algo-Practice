//https://vjudge.net/contest/219295#problemA
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
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

int gcd(int a, int b)
{
	if(b==1)
		return 1;
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}

int main()
{
	int n,m;
	while(true)
	{
		scanf("%d %d", &n, &m);
		if(n==-1 && m==-1)
			break;
		int ans = gcd(n,m);
		if(ans==1)
			printf("YES\n");
		else
			printf("POOR Haha\n");
	}
}
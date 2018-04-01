//http://poj.org/problem?id=1961
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

int main()
{
	int n,t=0;
	char str[1000010];
	while(true)
	{
		t++;
		scanf("%d", &n);
		if(n==0)
			break;
		scanf("%s", str);
		int len = strlen(str);
		int A[len];
		loop(i,0,len)
		{
			A[i]=0;
		}
		//Pre computing the prefix array for KMP 
		int j=0;
		loop(i,1,len)
		{
			if(str[i]==str[j])
			{
				A[i]=j+1;
				j++;
				continue;
			}
			while(j!=0)
			{
				j=A[j-1];
				if(str[j]==str[i])
				{
					A[i]=j+1;
					j++;
					break;
				}
			}
		}
		printf("Test case #%d\n", t);
		loop(i,2,len+1)
		{
			int diff = i-A[i-1];
			// Finding the current prefix which is also a suffix and then using the logic that it would be valid for all such pervious prefixes from that position
			if(i%diff==0 && diff!=len && i/diff>1)
				printf("%d %d\n", i, i/diff);
		}
		printf("\n");

	}
}
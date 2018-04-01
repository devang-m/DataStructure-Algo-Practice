//http://poj.org/problem?id=3461
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
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char text[1000010], word[10010];
		scanf("%s%s", word, text);
		int A[10005] = {0};
		int j=0;
		//Pre computing the prefix array for KMP 
		loop(i,1,strlen(word))
		{
			if(word[j]==word[i])
			{
				A[i]=j+1;
				j++;
				continue;
			}
			while(j!=0)
			{
				j=A[j-1];
				if(word[j]==word[i])
				{
					A[i]=j+1;
					j++;
					break;
				}
			}
		}
		int ans=0;
		j=0;
		// Doing the KMP search
		loop(i,0,strlen(text))
		{
			if(text[i]==word[j])
			{
				if(j==(strlen(word)-1))
				{
					ans++;
					//cout << i << " ";
					j=A[j];
				}
				else
				{
					j++;
				}
			}
			else
			{
				if(j!=0)
				{
					j=A[j-1];
					i--;
				}
			}
		}
		printf("%d\n", ans);
	}
}
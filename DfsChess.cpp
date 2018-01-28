//http://poj.org/problem?id=2488
#include <stdio.h>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
using namespace std;

int next_iter[8][2] = { { -2,-1 },{ -2,1 },{ -1,-2 },{ -1,2 },{ 1,-2 },{ 1,2 },{ 2,-1 },{ 2,1 } };
bool visited[26][26];
int p,q,ansx[26],ansy[26];
bool done=false;

void dfs(int x,int y, int c)
{
	visited[x][y]=true;
	ansx[c]=x;
	ansy[c]=y;
	c++;
	if(c==p*q)
	{
		done = true;
		loop(i,c)
		{
			printf("%c%d", ansx[i]+'A', ansy[i]+1);
		}
		done = true;
		printf("\n\n");
		return;
	}

	loop(i,8)
	{
		int newx= x+next_iter[i][0];
		int newy= y+next_iter[i][1];
		if(newx < 0 || newx >q-1 || newy < 0 || newy >p-1 || visited[newx][newy] || done)
			continue;
		dfs(newx,newy,c);
	}
	visited[x][y]=false;
}

int main()
{
	int n;
	scanf("%d", &n);
	loop(k,n)
	{
		scanf("%d%d", &p, &q);
		printf("Scenario #%d:\n", k+1);
		done = false;
		loop(i,q)
		{
			loop(j,p)
			{
				visited[i][j]=false;
			}
		}
		dfs(0,0,0);
		if(!done)
			printf("impossible\n\n");
	}
}
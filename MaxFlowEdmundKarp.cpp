//http://poj.org/problem?id=1273
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

int parent[205]={0},n,m;
bool f=true;

// Doing Simple BFS to see if an augmenting path still exists
void BFS(int capacity[205][205], vector<int> A[])
{
	bool visited[205];
	loop(i,0,205)
	{
		visited[i]=false;
		parent[i]=-1;
	}
	f=false;
	parent[1]=0;
	queue<int> q;
	q.push(1);
	visited[1]=true;
	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		loop(i,0,A[s].size())
		{
			if(capacity[s][A[s][i]]!=0 && visited[A[s][i]]==false)
			{
				visited[A[s][i]]=true;
				parent[A[s][i]]=s; // Storing the parent for each node in the augmenting path to retrace back
				q.push(A[s][i]);
				if(A[s][i]==m) // Showing that the augmenting path still exists
					f=true;
			}
		}
	}
}

int main()
{
	while(scanf("%d %d", &n, &m)!=EOF)
	{
		ll ans = 0;
		int capacity[205][205]={{0}};
		vector<int> A[205];
		loop(i,0,n)
		{
			int a,b,cap;
			scanf("%d %d %d", &a, &b, &cap);
			capacity[a][b]+=cap; // Storing the flow capacity between each node
			A[a].pb(b);
			A[b].pb(a);
		}
		BFS(capacity,A);
		while(f)
		{
			int k = m, max_flow=INF;
			while(parent[k]!=1)
			{
				// Finding the max flow which is the maximum flow that can move between the start and end, i.e. the minimum weight edge in the augmenting path
				max_flow = min(max_flow,capacity[parent[k]][k]);
				k = parent[k];
			}
			max_flow = min(capacity[1][k],max_flow); 
			ans+=max_flow;
			k = m;
			while(parent[k]!=1)
			{
				// Updating capacity for the forward and the backward edges
				capacity[parent[k]][k]-=max_flow;
				capacity[k][parent[k]]+=max_flow;
				k = parent[k];
			}
			capacity[1][k]-=max_flow;
			capacity[k][1]+=max_flow;
			BFS(capacity,A);
		}
		printf("%lld\n", ans);
	}
}
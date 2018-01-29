//https://vjudge.net/contest/209520#problem/F
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
	bool prime[10000]={0};
	prime[0]=true;
	prime[1]=true;
	for(int i=2;i<=100;i++)
	{
		if(!prime[i])
			for(int j=2*i;j<10000;j+=i)
				prime[j]=true;
	}
	// false if prime, true if not prime
	vector<int> A[10000];
	for(int i=1000;i<=9999;i++)
	{
		loop(j,4)
		{
			loop(k,10)
			{
				int num=i;
				if(j==3 && k==0)
					continue;
				num = (int)(i/(int)pow(10,j+1))*(int)pow(10,j+1) + k*((int)pow(10,j));
				if(j!=0)
					num += i%(int)pow(10,j);
				if(!prime[num])
					A[i].pb(num);
			}
		}
	}
	//loop(i,A[1033].size())
	//	cout << A[1033][i] << " ";
	int n;
	cin >> n;
	while(n--)
	{
		bool f=0;
		int start,end;
		cin >> start >> end;
		bool visited[10000]={0};
		int distance[10000]={0};
		queue<int> q;
		q.push(start);
		visited[start]=true;
		distance[start]=0;
		while(!q.empty())
		{
			int number = q.front();
			q.pop();
			if(number == end)
			{
				cout << distance[number] << endl;
				f=1;
				break;
			}
			loop(i,A[number].size())
			{
				int x = A[number][i];
				if(visited[x])
					continue;
				visited[x]=true;
				distance[x]=distance[number]+1;
				q.push(x);
			}
		}
		if(!f)
			cout << "Impossible\n";	
	}
}
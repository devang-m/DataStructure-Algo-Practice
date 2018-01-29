//http://poj.org/problem?id=1094
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
using namespace std;

vector<int> A[26];
vector<int> ans;
int indeg[26]={0};
int f=0,n;
bool done=0;

void top()
{
	int deg[26]={0},count=0,pos=-1;
	loop(i,26)
	{
		deg[i]=indeg[i];
	}
	loop(i,n)
	{
		count = 0;
		pos=-1;
		loop(j,n)
		{
			if(deg[j]==0)
			{
				count++;
				pos=j;
			}
		}
		if(count == 0)
		{
			f=1;
			return;
		}
		if(count>1)
		{
			f=2;
		}
		ans.pb(pos);
		deg[pos]=-1;
		loop(j,A[pos].size())
		{
			deg[A[pos][j]]--;
		}
		//loop(j,26)
		//	cout << deg[j] << " ";
	}
}

int main()
{
	int m;
	while(true)
	{
		loop(i,26)
		{
			A[i].clear();
			indeg[i]=0;
		}
		cin >> n >> m;
		if(n==0 && m==0)
			break;
		int j;
		done = 0;
		char a,b,dummy;
		for(j=0;j<m;j++)
		{
			ans.clear();
			f=0;
			cin >> a >> dummy >> b;
			indeg[b-'A']++;
			A[a-'A'].pb(b-'A');
			/*
			loop(i,26)
			{
				cout << indeg[i] << " ";
			}
			*/
			top();
			if(f==1)
			{
				cout << "Inconsistency found after " << j+1 << " relations.\n";
				done = true;
				break;
			}
			if(f==0)
			{
				cout << "Sorted sequence determined after " << j+1 << " relations: " ;
				loop(i,ans.size())
					cout << char(ans[i]+'A');
				cout << ".\n";
				done = true;
				break;
			}
		}
		for(int k=j+1;k<m;k++)
		{
			cin >> a >> dummy >> b;
		}
		if(!done)
		{
			cout << "Sorted sequence cannot be determined.\n";
		}
	}
	return 0;
}
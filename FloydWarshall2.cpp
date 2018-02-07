//http://poj.org/problem?id=1125
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;
int n;
int A[101][101]={{0}};

void floydwarshall()
{
	loop(i,n)
		loop(j,n)
			loop(k,n)
				A[j][k]=min(A[j][k],A[j][i]+A[i][k]);
} 

int main()
{
	while(true)
	{
		int m;
		cin >> n;
		if(n==0)
			break;
		loop(i,n)
		{
			loop(j,n)
			{
				if(i!=j)
					A[i][j]=1e7;
			}
		}
		loop(i,n)
		{
			cin >> m;
			loop(j,m)
			{
				int num,val;
				cin >> num >> val;
				A[i][num-1]=val;
			}
		}
		floydwarshall();
		/*
		loop(i,n)
		{
			loop(j,n)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		*/
		bool f=0;
		int maxi=0,most=1e7,pos=-1;
		loop(i,n)
		{
			f=0;
			maxi=0;
			loop(j,n)
			{
				if(i==j)
					continue;
				if(A[i][j]==1e7)
				{
					f=1;
					break;
				}
				maxi=max(maxi,A[i][j]);
			}
			if(!f)
			{
				if(maxi<most)
				{
					most=maxi;
					pos=i+1;
				}
			}
		}
		if(pos==-1)
			cout << "disjoint\n";
		else
			cout << pos << " " << most << "\n";
	}
}

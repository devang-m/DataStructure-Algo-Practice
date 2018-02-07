//https://vjudge.net/contest/211037#problem/E
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
double A[31][31];

void floydwarshall()
{
	loop(i,n)
		loop(j,n)
			loop(k,n)
				A[j][k]=max(A[j][k],A[j][i]*A[i][k]);
} 

int main()
{
	int num=1;
	while(true)
	{
		int m,c=0;
		cin >> n;
		if(n==0)
			break;
		map<string, int > ma;
		loop(i,n)
		{
			string s;
			cin >> s;
			ma[s]=c++;
		}
		loop(i,n)
		{
			loop(j,n)
			{
				if(i==j)
					A[i][j]=1;
				else
					A[i][j]=0;
			}
		}
		cin >> m;
		loop(i,m)
		{
			string s1,s2;
			double cost;
			cin >> s1 >> cost >> s2;
			A[ma[s1]][ma[s2]]=cost;
		}
		floydwarshall();
		bool f=0;
		loop(i,n)
		{
			if(A[i][i]>1)
				f=1;
		}
		cout << "Case " << num++ << ": ";
		if(f)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

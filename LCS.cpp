//https://vjudge.net/contest/208188#problemB
//Longest Common Subsequence for 2 sentences

/*
The input will contain several test cases. 
Each test case consists of two texts. Each text is given as a sequence of lower-case words, separated by whitespace, but with no punctuation. 
Words will be less than 30 characters long. Both texts will contain less than 100 words and will be terminated by a line containing a single '#'. 
Input is terminated by end of file.
For each test case, print the longest common subsequence of words occuring in the two texts. If there is more than one such sequence, any one is acceptable. 
Separate the words by one blank. After the last word, output a newline character.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#define loop(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
using namespace std;

int main()
{
	char s[32];
	while( scanf("%s", s)!=EOF)
	{
		string inp;
		vector<string> v1,v2;
		v1.pb(s);
		while(true)
		{
			cin >> inp;
			if(inp=="#")
				break;
			else
				v1.pb(inp);

		}
		while(true)
		{
			cin >> inp;
			if(inp=="#")
				break;
			else
				v2.pb(inp);
		}
		int l1=v1.size(), l2=v2.size();
		int A[l1+1][l2+1];
		loop(i,l1+1)
			loop(j,l2+1)
				A[i][j]=0;
		for(int i=1;i<=l1;i++)
		{
			for(int j=1;j<=l2;j++)
			{
				if(v1[i-1]==v2[j-1])
					A[i][j]=max(1+A[i-1][j],A[i][j-1]);
				else
					A[i][j]=max(A[i-1][j],A[i][j-1]);
			}
		}
		stack<string> ans;
		int len=A[l1][l2];
		int x=l1,y=l2;
		while(len!=0)
		{
			if(A[x-1][y]< A[x][y] && A[x][y-1]<A[x][y])
			{
				ans.push(v2[y-1]);
				len--;
			}
			if(A[x-1][y] > A[x][y-1])
				x--;
			else
				y--;
		}
		len = ans.size();
		loop(i,len-1)
		{
			cout << ans.top() << " ";
			ans.pop();
		}
		cout << ans.top() << "\n";
			ans.pop();
	}
}

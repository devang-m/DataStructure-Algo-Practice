//http://poj.org/problem?id=2250
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
#include <vector>
#include <stack>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while (cin >> s) {
    	vector<string> s1, s2;
    	s1.pb(s);
    	// Inputting the 2 strings
		while(true) {
			cin >> s;
			if(s=="#")
				break;
			s1.pb(s);

		}
		while(true) {
			cin >> s;
			if(s=="#")
				break;
			s2.pb(s);
		}
		int l1=s1.size(), l2=s2.size();
		int A[l1+1][l2+1];
		loop(i,0,l1+1)
			loop(j,0,l2+1)
				A[i][j]=0;
		// Getting the answer using DP
		for(int i=1;i<=l1;i++) {
			for(int j=1;j<=l2;j++) {
				if(s1[i-1]==s2[j-1])
					A[i][j]=max(1+A[i-1][j-1],max(A[i][j-1], A[i-1][j]));
				else
					A[i][j]=max(A[i-1][j],A[i][j-1]);
			}
		}
		stack<string> ans; // To store the answer
		int len=A[l1][l2];
		int x=l1,y=l2;
		while(len!=0)
		{
			if(s1[x-1]==s2[y-1]) // If positions are equal
			{
				ans.push(s2[y-1]);
				len--;
				x--;
				y--;
				continue;
			}
			if(A[x-1][y] > A[x][y-1])
				x--;
			else
				y--;
		}
		len = ans.size();
		loop(i,0,len-1)
		{
			cout << ans.top() << " ";
			ans.pop();
		}
		cout << ans.top() << "\n";
			ans.pop();
    }
}
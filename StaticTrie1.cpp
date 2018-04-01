//http://poj.org/problem?id=3630
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

int c;
bool ans;

// Using a static Trie because the dynamic Trie was timing out due to a lot of new memory allocation
struct TrieNode
{
	int child[10];
	bool endOfWord;
}node[100010];

// Making a Trie and doing the needed check
void maketrie(int root, char *str, bool f, int length)
{
	loop(i,0,length)
	{
		//cout << i ;
		int num = str[i]-'0';
		if(node[root].child[num]==0)
		{
			//cout << "New node" << i << "\n";
			f=1;
			node[root].child[num]=c++;
		}
		if(node[node[root].child[num]].endOfWord)
		{
			//cout << "Mismatch\n";
			ans = true;
		}
		if(i==length-1)
		{
			//cout << "End of word" << i << "\n";
			node[node[root].child[num]].endOfWord=true;
		}
		root=node[root].child[num];
	}
	if(!f)
		ans = true;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		memset(node,0,sizeof(node));
		scanf("%d", &n);
		c=2;
		char number[12];
		ans = false;
		while(n--)
		{
			scanf("%s", number);
			int len = strlen(number);
			maketrie(1,number,false,len);
		}
		if(ans)
			printf("NO\n");
		else
			printf("YES\n");
	}
}

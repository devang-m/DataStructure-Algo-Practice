//http://poj.org/problem?id=2001
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

// Using a dynamic trie
struct TrieNode
{
	TrieNode *child[26];
	bool endOfWord;
	int count;
};

void insert(TrieNode *root, char* s)
{
	TrieNode *cur = root;
	int len = strlen(s);
	//cout << len << endl;
	loop(i,0,len)
	{
		if(cur->child[s[i]-'a'] == NULL)
		{
			cur->child[s[i]-'a'] =  new TrieNode;
			cur = cur->child[s[i]-'a'];
			cur->count=1;
			loop(j,0,26)
				cur->child[j]=NULL;
			if(i==len-1)
				cur->endOfWord = true;
			else
				cur->endOfWord = false;
		}
		else
		{
			cur = cur->child[s[i]-'a'];
			cur->count+=1;
			if(i==len-1)
				cur->endOfWord = true;
		}
	}
}

string query(TrieNode *root, char* s)
{
	int len = strlen(s);
	string ans="";
	TrieNode *cur = root;
	loop(i,0,len)
	{
		int f=0;
		loop(j,0,26)
		{
			if(s[i]-'a'==j)
				continue;
			if(cur->child[j] != NULL || (cur->child[s[i]-'a']->count>1) || cur->endOfWord)
			{
				f=1;
				break;
			}
		}
		if(!f)
			return ans;
		ans = ans + s[i];
		cur = cur->child[s[i]-'a'];
	}
	return ans;
}

int main()
{
	int t,k=0;
	char A[1005][25];
	scanf("%d", &t);
	TrieNode *root = new TrieNode;
	loop(i,0,26)
		root->child[i]=NULL;
	root->endOfWord = false;
	root->count = 10000;
	while(scanf("%s",A[k]) != EOF)
	{
		k++;
		insert(root,A[k-1]);
	}
	loop(i,0,k)
	{
		cout << A[i] << " " << query(root,A[i]) << endl;
	}
}

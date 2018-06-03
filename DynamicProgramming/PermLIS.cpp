//http://www.spoj.com/problems/MCARDS/

/*
When Maverick gets his cards, he has to arrange them in groups so that all the cards in a group are of the same color. 
Next, he has to sort the cards in each group by their value – card with lowest value should be the leftmost in its group.

He has to arrange his cards as quickly as possible, i.e. making as few moves as possible. A move consists of changing a position of one of his cards.
*/

#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int> > iipair;

struct card
{
	int colour, number;
};

int perm[405];

/*
Finding the length of the Longest Increasing Subsequence in O((c*n)^2).
Returning the difference between c*n and the answer above
*/
int LIS(int c, int n)
{
	int B[c*n];
	loop(i,0,c*n)
	{
		B[i]=1;
	}
	loop(i,0,c*n)
	{
		loop(j,0,i)
		{
			if(perm[j] < perm[i])
				B[i]=max(B[i], B[j]+1);
		}
	}
	int maxi = 0;
	loop(i,0,c*n)
		maxi=max(maxi,B[i]);
	return (c*n-maxi);
}

/*
The idea is mainly to generate all permutations of the card colours. 
For 3 colours, there will be 3! permutations
1,2,3
1,3,2
2,1,3
2,3,1
3,1,2
3,2,1
Then using each of these permuations calculate the current permuation value of the holding cards and find the LIS of the sequence.
The answer is the minimum value of (c*n - the LIS) of all the permutations
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c,n, ans = INF;
	cin >> c >> n;
	card A[c*n];
	loop(i,0,n*c)
	{
		card lol;
		cin >> lol.colour >> lol.number;
		A[i]=lol;
	}
	vector<int> v;
	loop(i,1,c+1)
		v.pb(i); // Vector to store the permutations
	do
	{
		int pos[4];
		loop(i,0,c)
			pos[v[i]-1]=i; // Position of the colour in the current permutation
		loop(i,0,c*n)
		{
			perm[i]=pos[A[i].colour-1]*n+A[i].number-1; // Generating the new subsequence of cards based on the permutation
		}
		ans = min(ans,LIS(c,n));

	}while(next_permutation(v.begin(),v.end())); // Finding the next permutation

	cout << ans << endl;
}
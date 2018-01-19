// http://www.spoj.com/problems/FENTREE/
// Fenwick tree implementation for range sum query
#include <bits/stdc++.h>
#define LL long long
#define loop(i,n) for(int i = 0; i < n; i++)
using namespace std;
int n;

//Function to find the sum of elements from the start till the array position
LL sum(LL tree[], int pos)
{
	LL s=0;
	while(pos>0)
	{
		s+=tree[pos];
		pos-= pos & -pos; // To get the last bit and the subtracting it from the original to get the sum
	}
	return s;
}

//Function to update the tree
void update(LL tree[],int pos,int val)
{
	while(pos<=n)
	{
		tree[pos]+=val;
		pos+= pos & -pos; // To get the last bit and the adding it to the original to get the parent
	}
}
int main()
{
	int q;
	cin >> n;
	int A[n];
	loop(i,n)
	{
		cin >> A[i];
	}
	LL tree[n+1];
	loop(i,n+1)
	{
		tree[i]=0;
	}
	//Constructing the tree
	loop(i,n)
	{
		update(tree,i+1,A[i]);
	}
	cin >> q;
	while(q--)
	{
		char choice;
		int a,b;
		LL ans=0;
		cin >> choice >> a >> b;
		// Querying
		if(choice == 'q')
		{
			ans+=sum(tree,b); // Adding till the end of the range
			ans-=sum(tree,a-1); // Subtracting till the start of the range
			cout << ans << endl;
		}
		//Updating an element
		if(choice == 'u')
		{
			A[a-1]+=b;
			update(tree,a,b);
		}
	}

}

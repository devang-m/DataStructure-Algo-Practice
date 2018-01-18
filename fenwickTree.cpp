// http://www.spoj.com/problems/FENTREE/
// Fenwick tree implementation for range sum query
#include <bits/stdc++.h>
#define loop(i,n) for (int i = 0; i < n; i++)
using namespace std;
int n;
int sum(int B[], int pos)
{
	int s=0;
	while(pos>0)
	{
		s+=B[pos];
		pos-= pos & -pos;
	}
	return s;
}
void update(int B[],int pos,int val)
{
	while(pos<=n)
	{
		B[pos]+=val;
		pos+= pos & -pos;
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
	int B[n+1];
	loop(i,n+1)
	{
		B[i]=0;
	}
	//Constructing the tree
	loop(i,n)
	{
		update(B,i+1,A[i]);
	}
	cin >> q;
	while(q--)
	{
		char choice;
		int a,b,ans=0,val;
		cin >> choice >> a >> b;
		if(choice == 'q')
		{
			ans+=sum(B,b);
			ans-=sum(B,a);
			cout << ans << endl;
		}
		if(choice == 'u')
		{
			val=b-A[a-1];
			A[a-1]=b;
			update(B,a,val);
		}
	}

}

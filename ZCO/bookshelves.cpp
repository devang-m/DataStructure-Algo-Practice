//https://www.codechef.com/ZCOPRAC/problems/ZCO16001
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define INF 2147483647
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;

int main()
{
	int n,k,a;
	cin >> n >> k;
	multiset<int> m1,m2,m3,m4;
	multiset<int>::iterator itr1,itr2,itr3,itr4;
	loop(i,0,n)
	{
		cin >> a;
		m1.insert(a);
		m3.insert(a);
	}
	loop(i,0,n)
	{
		cin >> a;
		m2.insert(a);
		m4.insert(a);
	}
	while(k-- && n!=1)
	{
		int less1,less2,high1,high2;
		itr1=m1.end();
		itr2=m2.end();
		--itr1; --itr2;
		itr3=m1.begin();
		itr4=m2.begin();
		less1=*itr3;
		less2=*itr4;
		high1=*itr1;
		high2=*itr2;
		--itr1;
		--itr2;
		if(high1 > less2)
		{
			++itr1;
			m1.erase(itr1);
			m2.erase(itr4);
			m1.insert(less2);
			m2.insert(high1);
			/*
			cout << "Rekt ";
			for (multiset<int>::const_iterator i(m1.begin()), end(m1.end()); i != end;++i)
    			cout << *i << " ";
    		cout << "\nRekt ";
    		for (multiset<int>::const_iterator i(m2.begin()), end(m2.end()); i != end;++i)
    			cout << *i << " ";
    			*/
    			
		}
		itr1=m3.end();
		itr2=m4.end();
		--itr1; --itr2;
		itr3=m3.begin();
		itr4=m4.begin();
		less1=*itr3;
		less2=*itr4;
		high1=*itr1;
		high2=*itr2;
		--itr1;
		--itr2;
		if (high2 > less1)
		{
			++itr2;
			m3.erase(itr3);
			m4.erase(itr2);
			m3.insert(high2);
			m4.insert(less1);
			/*
			cout << "Lol ";
			for (multiset<int>::const_iterator i(m3.begin()), end(m3.end()); i != end;++i)
    			cout << *i << " ";
    		cout << "\nLol ";
    		for (multiset<int>::const_iterator i(m4.begin()), end(m4.end()); i != end;++i)
    			cout << *i << " ";
    			*/
    			
		}
	}
	itr1=m1.end();
	itr2=m2.end();
	itr3=m3.end();
	itr4=m4.end();
	itr1--; itr2--; itr3--; itr4--;
	cout << min((*itr1 + *itr2),(*itr3 + *itr4)) << endl;
}
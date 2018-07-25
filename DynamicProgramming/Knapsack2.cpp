//http://poj.org/problem?id=1276
// Knapsack problem with values allowed more than once
#include <iostream>
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
    int cash;
    while(cin >> cash) {
    	int n;
    	cin >> n;
    	int val[n], num[n];
    	loop(i,0,n)
    		cin >> num[i] >> val[i];
    	int A[100005][11] = {{0}}; // A[i][j] -> number of notes of jth denomination used to form cash i
    	loop(i,0,n) {
    		loop(j, val[i], cash+1) {
    			if((j-val[i]==0 || A[j-val[i]][0]!=0) && A[j-val[i]][i+1]!=num[i] && A[j][0]!=1) {
    				loop(k,0,n+1)
    					A[j][k] = A[j-val[i]][k];
    				A[j][i+1]++;
    				A[j][0]=1;
    			}
    		}
    	}
    	//cout << A[6][1] << " " << A[6][2] << endl;
    	int ans = 0;
    	loop(i,0,cash+1)
    		if (A[i][0]!=0)
    			ans = i;
    	cout << ans << endl;
    }
}


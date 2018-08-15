//http://poj.org/problem?id=1384
//Knapsack problem variation
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
    int t;
    cin >> t;
    while(t--) {
    	int e, f;
    	cin >> e >> f;
    	int weight_coins = f - e;
    	int n;
    	cin >> n;
    	// A[i][0] =  value of ith coin, A[i][1] = weight of ith coin
    	int A[500][2] = {{0}};
    	loop(i,0,n) {
    		cin >> A[i][0] >> A[i][1];
    	}
    	int ANS[weight_coins+1];
    	// Initialising all to maximum weight
    	loop(i,0,weight_coins+1)
    		ANS[i] = INF;
    	ANS[0] = 0;
    	// Adding all multiples of the coins
    	loop(i,0,n) {
    		loop(j,0,weight_coins+1-A[i][1]) {
    			// if the the existing value has come coins
    			if (ANS[j]!=INF) {
    				//cout << "Hi\n";
	    			ANS[j+A[i][1]] = min(ANS[j+A[i][1]], ANS[j]+A[i][0]);
	    		}
    		}
    	}
    	if(ANS[weight_coins]==INF)
    		cout << "This is impossible.\n";
    	else
    		cout << "The minimum amount of money in the piggy-bank is " << ANS[weight_coins] << ".\n";
    }
}
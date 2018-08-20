//http://poj.org/problem?id=3260
//Coin Change problem
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
    int t, n;
    cin >> n >> t;
    int A[n][2];
    loop(i,0,n)
    	cin >> A[i][0]; // Value of each coin
    loop(i,0,n)
    	cin >> A[i][1]; // Number of coins
    int total[11000][101]; // total[i][j] -> number of coins of jth denomination used to form i
    loop(i,0,11000) {
    	total[i][0] = INF; // total[i][0] -> total coins to form i
    	loop(j,1,101)
    		total[i][j] = 0;
    }
    total[0][0] = 0;
    loop(i,0,11000) {
    	int minimum = INF, val = INF;
    	loop(j,0,n) {
    		// To find the minimum number to get a certain value
    		if(i-A[j][0] >= 0 && total[i-A[j][0]][0]!=INF) {
    			if(total[i-A[j][0]][j+1] != A[j][1] && total[i-A[j][0]][0]+1 < minimum) {
    				minimum = total[i-A[j][0]][0]+1;
    				val = j;
    			}
    		}
    	}
    	// Replace when we find how to form i with least number of coins
    	if(val!=INF) {
    		loop(j,0,n+1) {
    			if(j!=val && j!=0)
    				total[i][j] = total[i-A[val][0]][j];
    			else
    				total[i][j] = total[i-A[val][0]][j] + 1;
    		}
    	}
    }

    int shopkeeper[11000];
    loop(i,0,11000)
    	shopkeeper[i] = INF;
    shopkeeper[0]=0;
    loop(i,0,11000) {
    	loop(j,0,n) {
    		if(i+A[j][0] < 11000 && shopkeeper[i]!=INF) {
    			shopkeeper[i+A[j][0]] = min(shopkeeper[i+A[j][0]], shopkeeper[i]+1);
    		}
    	}
    }

    int ans = INF;
    //cout << total[75][0] << " " << shopkeeper[5] << endl;
    loop(i,t,11000) {
    	if(total[i][0]!=INF && shopkeeper[i-t]!=INF) {
    		ans = min(ans, total[i][0]+shopkeeper[i-t]);
    		//cout << i << " " << ans << " " << total[i][0] << " " << shopkeeper[i-t] << endl;
    	}
    }

    if(ans == INF)
    	cout << -1 << endl;
    else
    	cout << ans << endl;
}


#include <iostream>
#define FOR(i,a,b) for(int i =(a); i <=(b); i++)
using namespace std;
 
/*
PROBLEM INFO:
    IN:
    - n: test cases
    - m | (m <= 100): # of coins in the bag
    - v[]: array of values of coins
    OUT:
    - minimal positive difference between the amount two persons obtain when they divide the coins from the corresponding bag
    IDEA:
    - adapted version of the knapsack problem
    COMPLEXITY:
    - O(n^2) as we are checking for each pair
*/
const int N = 300;
int t, n, v[N], s, dp[N][50500];
 
void calc() {
    FOR(i,0,n) {
        FOR(j,0,s/2) {
                if (i == 0 || j == 0) continue;
                dp[i][j] = dp[i-1][j];
                if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]]+v[i]);
        }
    }
    cout<<s-2*dp[n][s/2]<<endl;
}
 
void solve () {
    cin>>t;
    while(t--) {
        cin>>n;
        FOR(i,1,n) {
            cin>>v[i];
            s += v[i];
        }
        calc();
    }
}
 
 
int main(int argc, char const *argv[]) {
  solve();
  return 0;
}
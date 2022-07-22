#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<bool> vb;

const int INF = 1e9+10;
const int N = 20;

pii dp[ (1 << N) + 1];
int w[N];

int n;
int W;

void sol(){


    
    dp[0] = {0,0};

    FOR(m, 1, (1<<n) - 1){


        dp[m] = {INF, 0};
        
        FOR(i, 0, n-1){
            
            if(  (m &(1<<i)) == 0) continue;

            int mm =  (m ^ (1<<i));

            const pii candidate = dp[mm].S + w[i] <= W ? pii(dp[mm].F , dp[mm].S + w[i])
                                                         : pii(dp[mm].F + 1, w[i]);
            
            dp[m] = min(dp[m], candidate);

        }
        // auto bs = bitset< 4 > {m};
        // cout<<bs<<" ";
        // printf("(%d,%d)\n", dp[m].first, dp[m].second);
    }
 
    auto rides  = dp[ (1<<n) -1 ];
    
    // printf("(%d,%d)\n", rides.first, rides.second);
    
    cout<< (  (rides.S > 0) ? rides.F + 1 : rides.F  )<<endl;
}



int main(int argc, char const *argv[]) {

    cin>>n>>W;
    FOR(i,0,n-1) cin>>w[i];
    
    sol();
    return 0;
}
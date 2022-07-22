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
const int N = 5e3+10;

const int max_int = ~(1<<31);

int dp[N][N];

int v[N];
int w[N];
//First = num of items taken
//Second = previous item.
pii aux[N];


int W,n;

void sol(){

    aux[0].F = 0;
    aux[0].S = 0;
    
    FOR(i, 1, n){
        aux[i].F = i;
        aux[i].S = 0;
        
        FOR(j,1, W){            
            // dp[i][j] = max(dp[i][j], dp[i-1][j]);
            
            if(dp[i-1][j] > dp[i][j] ){
                dp[i][j] = dp[i-1][j];
                aux[i].F = aux[i-1].F;
                aux[i].S = aux[i-1].S; 
            }

            if(w[i] <= j &&)  dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i]);
        }

        // cout<<dp[i][W]<<" ";
    }


    // cout<<dp[n][W]<<'\n';
}


int main(int argc, char const *argv[]) {
    
    int t;

    
    while(cin>>W){
        cin>>n;

        FOR(i,1,n) cin>>v[i]>>w[i];
        memset(dp, 0,N*N );
        sol();
    }
   

    return 0;
}
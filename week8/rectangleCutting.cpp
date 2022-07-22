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
const int N = 5e2+10;

const int max_int = ~(1<<31);


int a,b;


int dp[N][N];


void sol(){

    FOR(i,0, a+1){
        FOR(j,0, b+1)
            dp[i][j] = INF;
    }
        
    FOR(i,0, max(a,b) + 1)  dp[i][i] = 0;

    FOR(i,1,a){

        FOR(j,1,b){

            FOR(i1, 1 , i)  dp[i][j] = min(dp[i][j],  dp[i - i1][j] + dp[i1][j] + 1 );
            
            FOR(j1, 1 , j)  dp[i][j] = min(dp[i][j],  dp[i][j - j1] + dp[i][j1]  + 1);
            
            // if(dp[i][j] == INF) cout<<"INF\t";
            // else cout<<dp[i][j]<<"\t";
        }
        // cout<<'\n';
    }

    cout<<dp[a][b]<<'\n';
}

int main(int argc, char const *argv[]) {

    cin>>a>>b;
    
    sol();
    return 0;
}
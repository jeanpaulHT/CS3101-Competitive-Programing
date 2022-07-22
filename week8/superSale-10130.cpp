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
const int N = 1000+ 10;

const int max_int = ~(1<<31);


int n,W;

int v[N], w[N];
int s;
int dp[N][N];

void sol(){
    W = 30;
    dp[0][0] = 0;

    FOR(i, 0, n){
        FOR(j,0,W){
            if(i == 0 || j == 0) {dp[i][j] = 0;continue;}
            dp[i][j] = dp[i-1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i][j], dp[i-1][j - w[i]] + v[i] );

        }
    }

    int g,wg,ans = 0;
    cin>>g;
    FOR(i,1,g){
        cin>>wg;
        ans+= dp[n][wg];
    }

    cout<<ans<<endl;
}

int main(int argc, char const *argv[]) {
    
    int t;
    cin>>t;

    while(t--){

        cin>>n;
        // s = 0;
        FOR(i,1,n) {
            cin>>v[i]>>w[i];
            // s+=v[i];   
        }
        sol();   

    }
 
    return 0;
}
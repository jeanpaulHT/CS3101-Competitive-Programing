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
const int N = 21;

int n, nn, mm, x, y, p, u, v, t;

int dp[N][1<<11];

vector<pii>a;

int dist(int u,int v){
    return abs(a[u].F - a[v].F) + abs(a[u].S- a[v].S);

}

void solve(){
    
    
    ROF(m, (1<<n) - 1,0){
        FOR(u,0,n-1){
            if(m == (1<<n) - 1){
                dp[u][m] = dist(u,0);
                continue;
            }

            dp[u][m] = INT_MAX;
            FOR(op,0,n-1){
                if( (m & (1<<op)) == 0 ){
                    dp[u][m] = min(dp[u][m], dist(u,op) + dp[op][m | (1<<op)] );
                }
            }

        }
    }
    cout<<"shortest path has lenght "<<dp[0][1]<<endl;

}


int main(int argc, char const *argv[]) {
    cin>>t;

    while(t--){
        a.clear();
        cin>>nn>>mm;
        cin>>x>>y;
        a.PB({x,y});
        cin>>p;
        FOR(i,1,p){
            cin>>x>>y;
            a.PB({x,y});
        }
        n = p + 1;
        solve();
    }
    return 0;
}
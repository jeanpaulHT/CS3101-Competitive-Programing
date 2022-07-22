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
const int N = 10;

const ll MOD = 1e9+7;
pii a[N];
int n,t;

double dp[N][(1<<N)];
int p[N][ (1<<N) ];



double dist(int u, int v){
    double p = sqrt(  (a[u].F - a[v].F)*  (a[u].F - a[v].F)  * 1.0  + 
     (a[u].S - a[v].S)*  (a[u].S - a[v].S) *1.0);

    return (u == v) ? p : p + 16;
}

void solve(){
    double ans = INF;
    int uu;
    ROF(m, (1<<n)- 1, 0){
        FOR(u,0,n-1){
            if( m == ( (1<<n) - 1) ) {
                dp[u][m] = 0.0;
                continue;
            }
            dp[u][m] = INT_MAX;
            FOR(op,0, n-1){
                if( (m & (1<<op) )== 0){
                    // dp[u][m] =  min ( dp[u][m] , dist(u, op) + dp[op][m | (1<<op)] );
                    if(dist(u,op) + dp[op][m | (1<<op)] < dp[u][m]){
                        p[u][m] = op;
                        dp[u][m] = dist(u,op) + dp[op][m | (1<<op)] ;
                    }
                }

                if(m == 0 and dp[u][m] < ans){
                    ans = dp[u][m];
                    uu = u;
                }

            }
        }
    }
    int u = uu;
    int m = (1<<u);
    while(true){

        if(m ==  ( (1<<n)-1 ) ) break;
		int u_t = p[u][m];
		int m_t = (m | (1<<u));

		printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", 	
		a[u].F, a[u].S, a[u_t].F, a[u_t].S, 
		dp[u][m]  - dp[u_t][m_t] );

        u = p[u][m];
        m = (m | (1<<u));

    }
    printf("Number of feet of cable required is %.2f.\n", ans);
}

int main(int argc, char const *argv[]) {

    t = 1;
    while(true){
        cin>>n;
        if(n == 0) break;
        FOR(i,0,n-1) cin>>a[i].F>>a[i].S;

        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<t++<<endl;
        solve();

    }

    return 0;
}
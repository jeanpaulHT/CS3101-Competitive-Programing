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
const int N = 8;

int n,t;

string s;

int x[2 * N + 1], y[2 * N + 1];

double dp[ (1 << (2* N)) ]; 


double dist(int i, int j){
    return  hypot(x[i] - x[j], y[i] - y[j]);
}

void solve(){
    


    int mm;
    dp[0] = 0;


    FOR(m, 1, (1<<(2*n))- 1 ){

        dp[m] = INF;
        int x = __builtin_popcount(m);
        if(x%2 == 1) {continue;}   

        FOR(i,0,2*n-2){
            
            FOR(j,i+1,2*n-1){
                
                if( (m & (1<<i)) == 0 ||   (m & (1<<j)) == 0) continue;


                mm = (m ^ (1 << i) ^ (1<<j));
                dp[m] = min(dp[m], dist(i,j) + dp[mm]);           


            }
        }

    }

    printf("%.2lf\n", dp[ ( 1<<(2*n)) - 1]);

}

int main(int argc, char const *argv[]) {

    t = 1;
    while(true){
        cin>>n;
        if(n == 0) break;
        
        FOR(i,0,2*n - 1){
            cin>>s>>x[i]>>y[i];
        }
        
        cout<<"Case "<<t++<<": ";
        
        solve();
    }

    return 0;
}
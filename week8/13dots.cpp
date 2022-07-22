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

const ll N = 5e3 + 10;
const ll INF = 1e9 + 10;

ll w,n,a[N],b[N];
ll best[5000]; //best[j] Maximo puntaje que puedo obtener con peso = j
ll ans;

void solve(){
    ll dp[200][500]; //dp[i][j] Maximo puntaje que puedo obtener usando los i primeros items con peso = j.
    FOR(i,0,n){
        FOR(j,0,w+200){
            if(i==0 and j==0) dp[i][j] = 0;
            else if(j == 0) dp[i][j] = 0;
            else if(i == 0) dp[i][j] = -INF;
            else {
                dp[i][j] = dp[i-1][j];
                if(a[i] <= j) dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]] + b[i]);
            }
        }
    }
    FOR(j,0,w+200){
        best[j] = dp[n][j];
    }
    ans = 0;
    FOR(j,0,w+200){
        if(w < j and j <= 2000) continue;
        ans = max(ans,best[j]);
    }
    cout << ans;
}

int main() {
    while(cin >> w >> n){
        FOR(i,1,n) cin >> a[i] >> b[i];
        solve();
    }
    return 0;   
}
/*********************************DOCUMENTACIÓN*********************************

Complejidad de tiempo = O(*) con *=?
Complejidad de espacio = O(*) con *=?

*******************************************************************************/

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define P pop_back

#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define SFOR(i,a,b,s) for(ll i=(a); i<=(b); i=i+(s))
#define ROF(i,a,b) for(ll i=(a);i>=(b);i--)
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SORT(v) sort((v).begin(), (v).end())
#define ASORT(v,n) sort((v), (v)+(n))
#define RSORT(v) sort((v).begin(), (v).end(), std::greater<>())
#define RASORT(v,n) sort((v), (v)+(n), std::greater<>())
#define P pop_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<bool> vb;

const ll N = 5e3 + 10;
const ll INF = 1e9 + 10;

ll a[N], t = 0, x, dp[N] = {1}, ans[N], m = 0;

int main() {
    while(cin>>x){
        if(x==0) break;
        a[t++] = x;
    }

    FOR(i,1,t-1){

      FOR(j,0,i-1){
          if (a[j] > a[i]) {
            dp[i] = max(dp[i] + 1,dp[j]);
          }
      }

    }
    ll s = 0;
    FOR(i,0,t-1) s = max(s,dp[i]);
    cout << s;
}
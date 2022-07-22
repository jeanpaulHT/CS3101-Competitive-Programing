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
#define left(x) 2*x
#define right(x) 2*x+1

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

const ll INF = 1e9 + 10;
const ll N = 1e6 + 100;

ll m,fixes[N];
string s;

void calc_fixes(){
    ll k = 0;
    fixes[0] = 0;
    FOR(q,1,m-1){
        while(k > 0 and s[k] != s[q]){
            k = fixes[k-1];
        }
        if(s[k] == s[q]){
            k = k + 1;
        }
        fixes[q] = k;
    }
}

int main() {


    #ifndef ONLINE_JUDGE
        // For getting input from input.txt file
        freopen("in", "r", stdin);
        // Printing the Output to output.txt file
        freopen("out", "w", stdout);
        //Printing errors in out file
        freopen("out", "w", stderr);
    #endif

    while(true){
        cin >> s;
        if(s==".") break;
        m = s.size();
        calc_fixes();

        FOR(i, 0, m-1){
            cout<<fixes[i]<<' ';
        }
        cout<<'\n';
        cout << m / (m - fixes[m-1]) << endl;
    }
    
    return 0;
}
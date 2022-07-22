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
const int N = 1e6+10;



int pi[N],n,m,k,q;
string p,t;


void build(){
    pi[0] = 0;
    k = 0;
    m = sz(p);
    FOR(q,1,m-1){
        while(k > 0 and p[k] != p[q]) k = pi[k-1];    
        
        if(p[k] == p[q]) k++;
        pi[q] = k;    
    }
}

void solve(){
    n = sz(t);
    m = sz(p);
    q = 0;
    int ans = 0;
    FOR(i,0,n-1){
        while(q > 0 and p[q] != t[i]) q = pi[q-1];
        if(p[q] == t[i]) q++;
        if(q==m){
            ans++;
            q = pi[q-1];
        }
    }
    cout<<ans<<endl;
}


int main(int argc, char const *argv[]) {


    #ifndef ONLINE_JUDGE
        // For getting input from input.txt file
        freopen("in", "r", stdin);
        // Printing the Output to output.txt file
        freopen("out", "w", stdout);
        //Printing errors in out file
        freopen("out", "w", stderr);
    #endif
    
    cin>>t>>p;
    build();
    solve();
    return 0;
}
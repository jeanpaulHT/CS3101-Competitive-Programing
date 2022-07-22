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
const int N = 2e5+10;

vector<vector<int>> adj;
vector<int> sol;

bool vis[N] {0};

int n,m,a,b,cont;



void dfs(int u){

    vis[u] = 1;
    
    for(auto v: adj[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}

void solve(){


    FOR(u, 1, n){
        if(vis[u]) continue;
        dfs(u);
        cont++;
        sol.push_back(u);

    }
    cout<<sz(sol) - 1<<'\n';

    FOR(i,0, sz(sol)-2){
        cout<<sol[i]<<" "<<sol[i+1]<<'\n';
    }
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


    cin>>n>>m;

    adj.resize(n+1);

    FOR(i,1,m){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);    
    } 


    solve();

    return 0;
}
/*********************************DOCUMENTACIÓN*********************************

O():

*******************************************************************************/

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define P pop_back

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define SFOR(i,a,b,s) for(int i=(a); i<=(b); i=i+(s))
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<bool> vb;

const int N = 2e5 + 10;
const int INF = 1e9 + 10;

vll adj[N];
ll n,m,pre[N],scc[N],low[N],cont,scc_cont;
stack<ll> pila;

// O(V+E), dfs normal. procesar la cola se hace en O(V)
void dfs(ll u){
    pre[u]=cont++;
    pila.push(u);
    low[u]=pre[u];
    for(auto v: adj[u]){
        if(pre[v]!=-1) {
            if(scc[v]==-1) low[u]=min(low[u],pre[v]);
            continue;
        }
        dfs(v);
        low[u]=min(low[u],low[v]);
    }
    if(low[u]==pre[u]){ //u es la cabeza de su scc
        ll w;
        do {
            w = pila.top();
            pila.pop();
            scc[w]=scc_cont;
        } while(w!=u);
        scc_cont++;
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


    ll u,v;
    cin >> n >> m;
    scc_cont=cont=0;
    // Cuando hay varios tests:
    // FOR(e,1,n) adj[e].clear();
    FOR(e,1,m){
        cin >> u >> v;
        adj[u].PB(v);
    }
    FOR(e,1,n) pre[e]=scc[e]=-1;
    FOR(u,1,n){
        if(scc[u]==-1){
            dfs(u);
        }
    }
    cout << scc_cont << endl;
    // Le resto a scc_cont solo para que la solucion
    // haga match con los tests de cses
    FOR(u,1,n) cout << scc_cont - scc[u] << " ";
    return 0;
}
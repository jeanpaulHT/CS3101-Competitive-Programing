/*


2. Expliquen bien el por qué de la complejidad.

Mal. Mi complejidad es O(n).
Bien. Mi complejidad es O(n) porque...

3. Expliquen bien la idea.

Mal: Hago tsp.
BIen. Hago tsp. El tsp consiste en .., funciona porque...


*/

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

int t;
vi adj[N];
int c,p,x,l;
int estado[N];
int in[N], cur[N];
vi topo;


void dfs(int u){
    //procesando
    estado[u] = 1;
    for(auto v: adj[u]){
        if(estado[v] == 2) continue;
        if(estado[v] == 1){
            exit(EXIT_SUCCESS);
        }
        dfs(v);
    }

    estado[u] = 2;
    topo.PB(u);
}

void solve(){
    //TODO:
    //start from change file
    for(auto v: adj[l]){
        cur[v]--;
    }
    cur[l] = 0;
    for(auto v: adj[l]){
        dfs(v);
    }
}


void read(){
    cin>>c>>p>>x>>l;

    topo.clear();
    FOR(i,1,c){
        adj[i].clear();
        estado[i] = in[i] =  0;
    }

    int x,y;
    FOR(i,1,p){

        cin>>x>>y;
        adj[y].PB(x);
        adj[x].PB(y);
        cur[x] = ++in[x];
        cur[y] = ++in[y];
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

    read();
    solve();


    return 0;
}
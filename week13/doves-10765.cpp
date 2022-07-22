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
const int N = 2e5+100;

vector<int> adj[N];
int pre[N], low[N];
int n,u,v,k,cont;
int arts[N];

void dfs(int u, int p){
    pre[u]=cont++;
    low[u] = pre[u];
    int num_hijos = 0;
    arts[u] = 1;

    for(auto v: adj[u]){
        if(pre[v]){
            if(p != v){
                low[u] = min(low[u], pre[v]);
            }
            continue;
        }

        dfs(v,u);

        if(u!= p and low[v] >= pre[u]){
            arts[u]++;
        }
        low[u] = min(low[u], low[v]);
        num_hijos++;
    }

    if(u == p and num_hijos>1){
        arts[u]= num_hijos;
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

    
    while(true){
        cin>>n>>k;
        if(n == 0 && k == 0) break;


        FOR(u,0,n-1){
            adj[u].clear();
            low[u] = pre[u] = 0;
        }

        while(true){
            int u,v;
            cin>>u>>v;
            if(u == -1 && v==-1) break;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cont = 1;
        dfs(0,0);
        vector<pii> sol;

        FOR(u,0,n-1){
            sol.push_back({-arts[u],u});
        }

        sort(sol.begin(),sol.end());
        FOR(i,0,k-1){
            cout<<sol[i].S<<" "<<-sol[i].F<<'\n';
        }
        cout<<endl;
    }
    return 0;
}
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

int n,k,u,v,pre[N], low[N], cont;
char c;
vector<pii> bridges;
vi adj[N];

void dfs(int u, int p){
    pre[u]=cont++;
    low[u] = pre[u];
    for(auto v: adj[u]){
        if(pre[v]){
            if(p != v){
                low[u] = min(low[u], pre[v]);
            }
        }
        else{
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            if(low[v]  == pre[v]) bridges.push_back({min(v,u), max(v,u)});
        }
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
    
    while(cin>>n){
        FOR(i,1,n){
            scanf("%d",&u);
            scanf("%c%c%d%c",&c,&c,&k,&c);
            FOR(j,1,k){
                cin>>v;
                adj[u].PB(v);
            }
        }

        bridges.clear();
        cont = 1;
        FOR(u,0,n-1){
            if(!pre[u]) dfs(u,u);
        }
        cout<<sz(bridges)<<" critical links"<<endl;
        sort(all(bridges));
        for(auto b: bridges){
            cout<<b.F<<" - "<<b.S<<endl;
        }
        cout<<endl;
    }
    return 0;
}
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

vi adj[N];
int in[N];
int n,m;
vi topo;
map<string,int> mapa;
map<int,string> mapaR;
int t;




//bfs Kahn
void solve(){
    set<int> s;
    FOR(u,1,n){
        if(in[u] == 0) 
            s.insert(u);
    }
    while(!s.empty()){
        int u = *(s.begin());
        s.erase(u);
        topo.PB(u);
        for(auto v: adj[u]){
            in[v]--;
            if(in[v] == 0) s.insert(v);
        }
    }
    std::cout<<"Case#"<<t++<< ": Dilbert should drink beverages in this order: ";
    for(auto u: topo) cout<<mapaR[u]<<" ";

}

void read(){
    string s;
    
    mapa.clear();
    mapaR.clear();
    topo.clear();

    FOR(u,1,n){
        cin>>s;
        mapa[s] = u;
        mapaR[u] = s;
        in[u] = 0;
        adj[u].clear();
    }
    cin>>m;
    FOR(e,1,m){
        string s,t;
        cin>>s>>t;
        adj[mapa[s]].PB(mapa[t]);
        in[mapa[t]]++; 
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
    t = 1;

    while(cin>>n){
        read();
        if(n == 0)break;
        solve();
        cout<<'\n';
    }
    return 0;
}
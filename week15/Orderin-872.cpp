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
int in[N],vis[N];
int n,m;
vi topo;
map<char,int> mapa;
map<int,char> mapaR;
int t;
string line;

void read(){
    string s;
    mapa.clear();
    mapaR.clear();
    FOR(u,1,n){
        in[u] = vis[u] = 0;
        adj[u].clear();
    }
    getline(cin, line);
    stringstream ss;
    ss.clear();
    ss.str(line);
    char c;
    int  i = 1;
    while (ss>>c){
        mapa[c] = i;
        mapaR[i]= c;
        i++;
    }
    n = i -1;
    getline(cin,line);
    ss.clear();
    ss.str(line);
    char a,b;
    while(ss>>a>>b>>c){
        adj[mapa[a]].PB(mapa[c]);
        in[mapa[c]]++;
    }
}
void bck(int i){
    if(i == n){
        for(auto v: topo) cout<<mapaR[v]<<" ";
        cout<<'\n';
        return ;
    }
    FOR(u,1,n){
        if(in[u] == 0 and vis[u] == 0){
            topo.PB(u);
            vis[u] = 1;
            for(auto v: adj[u]) in[v]--;
            bck(i+1);
            topo.pop_back();
            for(auto v: adj[u]) in[v]++;
            vis[u] = 0;
        }
    }

}


//bfs Kahn
void solve(){
    topo.clear();
    bck(0);
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
    
    cin>>t;
    getchar();
    string linea;
    while(t--){
        getline(cin,linea); 
        read();

        if(n == 0)break;
        solve();
    }
    return 0;
}
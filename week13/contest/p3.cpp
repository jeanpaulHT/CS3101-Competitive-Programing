/*



Complejidad algoritmica:
O( (|v| + |E|))

v: conjunto de vertices
E: conjuntos de aristas


Es un algoritmo de trajan, y como sabemos la al  ser un recorrido DFS la complejidad es
O(|v| + |E|). El funcionammiento del algoritmo de trajan es similar a los de los 2 anteriores
ejercicios.

Lo que tenemos que buscar aqui
Son los puentes del grafo y aumentar el numero de aristar de esa vertice 
hacia cualquier otra vertice que no sea la su padre ene el arbol de recorrido T.

*/


#include <vector>
#include <string>
#include <utility>
#include <iostream>

using namespace std;

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


int n,m,t,tc;
int pre[N],low[N];
vi adj[N];
int cont;
int cont_res;

int arts[N];

vector<pii> res;


// void dfs(int u, int p){
//     pre[u] = cont++;
//     low[u] = pre[u];

//     int num_hijos = 0;
//     for(int i = 0; i < sz(adj[u]); i++){
//         int v = adj[u][i];
//         if(pre[v]){
//             if(v != p){
//                 low[u] = min(low[u], pre[v]);
//             }
//             continue;
//         }

//         dfs(v,u);
//         low[u] = min(low[u], low[v]);
//         if(u != p && pre[u] <= low[v] ){
//             arts[u]++;
//         }
        
//         num_hijos++;
//     }

//     // if(u == p){
//     //     arts[u] = num_hijos;
//     // }
    
//     if(arts[u] > 0) cont_res++;
// }


void dfs(int u, int p){
    pre[u] = cont++;
    low[u] = pre[u];

    for(int i = 0; i < sz(adj[u]); i++){
        int v = adj[u][i];
        if(pre[v]){
            if(v != p){
                low[u] = min(low[u], pre[v]);
            }
            continue;
        }

        dfs(v,u);
        if(low[v] == pre[v]){
            res.PB( pair<int,int>(u,v));
        }
        low[u] = min(low[u], low[v]);
    }
}


void sol(){

    cont = 1;
    cont_res = 0;

    dfs(1,1);

    // FOR(i,1,n-1){
    //     printf("[%d](%d),", i, arts[i]);
    // }
    cout<<sz(res) - 1;
    cout<<'\n';
    res.clear();
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

        FOR(j,0,n){
            adj[j].clear();
            arts[j] = pre[j] = low[j] = 0;
            
        }

        FOR(j,0,m-1){
            int x,y;
            cin>>x>>y;

            adj[x].PB(y);
            adj[y].PB(x);
        }

        sol();
    

    return 0;
}
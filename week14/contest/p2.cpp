/*

La complejidad del problema es:

O(tc * v^2 O(|V| + |E| + |S|))

tc: el numero de test cases
V: conjunto de vertices
E: conjunto de aristas
S: es el conjunto de vertices que pueden estar en el stack
    (puede remuever a todas el conjunto en el peor caso V)

La complejidad es tal debido a que:
Por cada test case: (tc)
    recibir el input de vertices (n^2)
    correr algoritmo de tarjan: (|V|+|E|+|S|)
        -> hace un dfs (|V| + |E|)
        -> remover los nodos que estan en S (|S|) 

La resolucion del problema se puede resumir en identificar el numero de componenetes
fuertemente conexos que estan en un grafo dirigido.
Lo cual se puede encontrar apartir de algoritmo de tarjan scc.
Debido a la invariante que:
-> va insertando en el stack los nodos
-> una vez encontrado un componente, lo remove del stack 
-> los nodos que quedan siguen siendo candidatos para ser parte de otro componente


somos capaces de encontrar la repuesta.

Como sabemos que empieza remover del stack un componente, una vez que se haya 
encontrado todos sus vertices. Simplemente tenemos que encontrar el numero de veces
que se vacia el stack.
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
const ll modulo = 1e9 + 7;

stack<ll> s;

ll scc[N],pre[N], low[N], m,n;
ll  cont, cont_scc;
vll adj[N];

//test var
ll t,tc;
//cost var
ll cost[N];
ll min_scc_cost[N];
ll min_scc_rep[N];


void dfs(int u){
    
    pre[u] = cont++;
    s.push(u);
    low[u] = pre[u];

    for(auto v: adj[u]){
        if(pre[v] != -1){
            if(scc[v] == -1){
                low[u] = min(low[u], pre[v]);
            }
            continue;
        }
        
        dfs(v);
        low[u] = min(low[u], low[v]);   
    }

    // cout<<u<<'\n';
    int w;
    if(low[u] == pre[u]){
        
        do{
            w = s.top();
            s.pop();
            scc[w] = cont_scc;
        }while(w != u);
        cont_scc++;
    }
}


void solve(){

    cont = cont_scc = 0;
    FOR(i,1,n){
        if(scc[i] == -1)
            dfs(i);
    }
    
    FOR(i,1,n){
        ll c = scc[i];
        if(min_scc_cost[c] > cost[i]){
            min_scc_rep[c] = 1;
            min_scc_cost[c] = cost[i];
        }
        else if( min_scc_cost[c] == cost[i]){
            min_scc_rep[c]++;
        }
        
        // printf("%lld [%lld] ->", c, min_scc_cost[c]);
        // cout<<cost[i];
        // cout<<'\n';
    }

    ll total_cost = 0;
    ll total_rep = 1;
    FOR(c,0,cont_scc - 1){
        total_cost =  ((total_cost) + (min_scc_cost[c] )) ; 
        total_rep = (total_rep * (min_scc_rep[c] ) ) % modulo;
    }

    printf("%lld %lld\n",total_cost, total_rep);

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

 
        cin>>n;
        
        FOR(i,0,n){
            min_scc_cost[i] = cost[i] = INF;
            min_scc_rep[i] = 0;
        }
        
        FOR(i,1,n){
            adj[i].clear();
            pre[i] = low[i] = scc[i] = -1;
            min_scc_cost[i] = cost[i] = INF;
            

            cin>>cost[i];
        }
        cont = cont_scc = 0;

        cin>>m;
        FOR(i,1,m){
            int x,y;
            cin>>x>>y;
            adj[x].PB(y);
        }

        // FOR(u,1,m){
        //     cout<<u<<": ";
        //     for(auto v: adj[u]){
        //         cout<<v<<' ';
        //     }
        //     cout<<'\n';
        // }
        

        solve();        
    




    return 0;
}
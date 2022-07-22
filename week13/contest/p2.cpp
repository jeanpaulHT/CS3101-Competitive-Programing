/*


Complejidad algoritmica:
O(tc * (|v| + |E|))

tc: el numero de test
v: conjunto de vertices
E: conjuntos de aristas

en resumen, lo que se quiere buscar para el output son el numero de 
articulaciondes del grafo.
Sabemos que las articulaciones son definidas como las vertices (que al eliminarse) aumenta
el numero de componentes del grafo en al menos 1.

Para eso usuamos un dfs modificado que los encuentra, por lo que su complejidad es
O(|v| + |E|) ya que recorrera los vertices o aristas una vez.

Con este algotirmo tenemos un arbol de recorrido T generado por el dfs,
el valor pre de cada nodo es el numero de visita del nodo haciendo el recorrido del DFS
pres = 1 si es el primer visita, pre = 2 si es el segundo, y asi.

low de un nodo u es que tan arriba en el arbol T usando los ancestros en comun de sus descendientes.
o usando los nodos ascendientes (vecinos cuyo valoa a pre es menor a u). Sin tener
que ir al padre. En el caso base, lo mas arriba que puedes desde u es u mismo.


Como encontramos la articulacion:

imaginemo que tenemos un circuito tal que:
----------------
|               |
u ----- v ----- z  

si hay un circuito y quitamos v ,y sus edges,  aun tendremos un camino alternativo
para llegar de u a z. Por lo que podemos decir que si encontramos alguna vertice
que no este en un circuito, al removerla tendremos aumentaremos el numero de componentes.


Por lo que lo unico que tenemos que revisar en nuestro algoritmo, es si algun nodo
z (que sea descendiente de v) que no pueda
ir hacia u (nodo descendiente), es decir que no forme circuito.

Si no lo hace aumentamos el contador de articulaciones (cont_res) en 1.
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


int n,m,t,tc;
int pre[N],low[N];
vi adj[N];
int cont;
int cont_res;

int arts[N];

vector<pii> res;


void dfs(int u, int p){
    pre[u] = cont++;
    low[u] = pre[u];

    int num_hijos = 0;
    for(auto v: adj[u]){
        if(pre[v]){
            if(v != p){
                low[u] = min(low[u], pre[v]);
            }
            continue;
        }

        dfs(v,u);
        low[u] = min(low[u], low[v]);
        if(u != p && pre[u] <= low[v] ){
            arts[u]++;
        }
        
        num_hijos++;
    }

    // if(u == p){
    //     arts[u] = num_hijos;
    // }
    
    if(arts[u] > 0) cont_res++;
}

void sol(){

    cont = 1;
    cont_res = 0;

    dfs(1,1);

    // FOR(i,1,n-1){
    //     printf("[%d](%d),", i, arts[i]);
    // }
    cout<<cont_res;
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


    while(cin>>n>>m){
        
        if(n == 0 && m == 0) break;

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
    }

    return 0;
}
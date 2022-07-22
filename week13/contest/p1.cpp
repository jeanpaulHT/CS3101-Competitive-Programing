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


Por lo que al ver que el low[u] == low[u] significa que desde ese nodo, lo mas alto que 
puedes subir hacia arriba de T, es el mismo nodo. Por lo que no hay camino hacia arriba:
    - por alguno de los descendientes de u
    - O conexion con algun nodo ascendente

lo que significa que no habra camuino el cual pueda replazar a u.
Asi que lo consideramos un puente.

despues simplemente nos aseguramos cumplir las condiciones de ordenacion para los camino
{xi,yi}
que xi<yi
y que este ordenado de forma descendente tanto para x y luego y.
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

vector<pii> res;


void dfs(int u, int p){
    pre[u] = cont++;
    low[u] = pre[u];

    for(auto v: adj[u]){
        if(pre[v]){
            if(v != p){
                low[u] = min(low[u], pre[v]);
            }
            continue;
        }

        dfs(v,u);
        if(low[v] == pre[v]){
            res.PB({min(u,v),max(u,v)});
        }
        low[u] = min(low[u], low[v]);
    }
}

void sol(){

    cont = 1;
    dfs(1,1);


    sort(all(res), [](const pii& p1, const pii& p2){
        return p1.F < p2.F || (p1.F == p2.F && p1.S < p2.S);
    });

    printf("Caso #%d\n",tc);

    if(sz(res) == 0){
        cout<<"Sin bloqueos\n";
        return ;
    }

    cout<<sz(res)<<'\n';
    for(auto it: res){
        cout<<it.F<<" "<<it.S<<'\n';
    }

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

    cin>>t;


    for(tc = 1; tc <= t;tc++){
        
        cin>>n>>m;

        FOR(j,0,n){
            adj[j].clear();
            pre[j] = low[j] = 0;
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
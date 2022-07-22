/*

Complejidad algoritmica: O(tc * |v||v-1| )

tc: el numero de casos
v : el conjunto de vertices

al recebir las vertices y sus adjacentes hacesmos un recorrido dfs con bicoloramiento
este recorrido en el (peor de  los casos tendria que revisar cada vertice y cada vertice tendria
un edge hacia las demas vertices. O(|v|*|v-1|))

el cual colorea con un color c al nodo actual, revisa sus vecinos.  si el vecino ya fue visitado
y su color es igual al nodo actual, significa que el bicoloramiento no es posible. Debido
a que tendiramos 2 nodos adyacentes del mismo color.

si no es un nodo visitado aplicamos el recorrido dfs recursivo y retornamos 
falso si su resultado es falso. Lo cual funciona por la logica de arriba.

Aplicamos este dfsbicol a todos los componentes del grafo. Por lo que
recorremos todos los nodos; aplicamos dfsbicol y luego lo volvemos a aplicar cuando encontremos
a un nodo no-visitado. Si en alguna parte de esta iteracion el dfsbicol fallo, 

printemos que no es bicolorable. Caso contrario, que si lo es.

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
const int N = 1024 + 10;

vector<vector<int>> adj;
bool vis[N];
bool col[N];


int n,m;


bool bicol(int u, int c){
    
    vis[u] = true;
    col[u] = c;

    for(auto v: adj[u]){
        if(vis[v]){
            if(col[v] == c) return false;
        }
        else{
            bool b = bicol(v,!c);
            if(b == false) return false;
        }
    }

    return true;
}

void sol(){

    bool b = true;
    FOR(i,0,n-1){
        if(vis[i]) continue;

        b = b && bicol(i,1);
        if(!b) break;
    }

    if(b){
        cout<<"BICOLORABLE\n";
    }
    else{
        cout<<"NOT BICOLORABLE\n";
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

    while (cin>>n){
        if(n == 0) break;
        
        memset(vis,0,N * sizeof(bool));
        memset(col,0,N * sizeof(bool));

        cin>>m;
        
        adj.reserve(n);
        int x,y;
        FOR(i,1,m){
            cin>>x>>y;
            adj[x].PB(y);
            adj[y].PB(x);
        }
        sol();

        // FOR(i,0,n-1){
        //     for(auto v: adj[i]){
        //         cout<<i<<" "<<v<<'\n';
        //     }
        // }

        FOR(i,0,n-1){
            adj[i].clear();
        }
        adj.clear();

        
    }
    

    

    return 0;
}
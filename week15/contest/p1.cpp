/*

complejidad algoritmica:
O(V^2)

La complejidad es de esa manera debido a que un recorrio dfs tiene como
complejidad O(E + V).

Para poder a hallar todos los caminos que posibles tendriamos que implementar
un recorrido khan con backtracing. Lo cual nos llevaria a explorar
las elecciones posibles para estos caminos que seria O(V^2)

Esto serviria ya que al encontrar un camino podemos elegir el camino
que cumpla con las condicones que se piden.
(que i el elemento sea el menor).

Si en el backtraking no se encontro ningun camino cuyo tamaño sea el numero
de vertices. Significa  que hay doble dependencias en alguna parte, por lo que
no es posible para sandro cumplir con todas las tareas. 
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
int n,m;
int in[N];
vi topo;


void read(){
    cin>>n>>m;

    topo.clear();
    FOR(i,1,n){
        adj[N].clear();
        in[i] = 0;
    }

    //base: dependecies
    
    int x,y;
    FOR(i,1,m){
        cin>>x>>y;
        adj[y].PB(x);
        in[x]++;
    }
}

void khan(){
    set<int> s;
    FOR(u,1,n){
        if(in[u] == 0) s.insert(u);
    }

    while (!s.empty()){
        int u = *(s.begin());
        s.erase(u);
        topo.PB(u);
        for(auto v: adj[u]){
            in[v]--;
            if(in[v] == 0) s.insert(v);
        }
    }

    if(sz(topo) != n){
        cout<<"Sandro fails.\n";
    }
    for(auto u: topo){
        cout<<u<<" ";
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
    khan();


    return 0;
}
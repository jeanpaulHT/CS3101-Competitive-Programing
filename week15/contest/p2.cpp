/*

complejidad algoritmica:
O(E + V  + (E * v))

La complejidad es de esa manera debido a que un recorrio dfs tiene como
complejidad O(E + V).

La lectura de tambien tiene una complejidad de O( E * V)
esto es debido, porque se hace una busqueda en el mapa O(V) para 
ver si una vertice existe, sino existe se le asigna una id.
Luego se lo inserta al mapa. 

hacemos uso del algoritmo de recorrido dfs
para poder encontrar el camino de updates. Una manera de verlo, es
encontrar el camino de las dependencias.

En el grado representamos la dependencias de la siguiente manera:

si tenemos una libreria v que depende u, la representariamos como:
u -> v

Lo que hace el algoritmo es hallar el camino topologico de estas deendencias.

Esto funciona para el problema, ya que a empezar a recorrer desde 
la libreria cambiada, podemos hallar este camino.
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
int estado[N];
vi topo;

string change;
map<string,int> mapa;
map<int,string> mapaR;

void dfs(int u){
    //procesando
    estado[u] = 1;
    
    for(auto v: adj[u]){
        if(estado[v] == 2) continue;
        if(estado[v] == 1){
            exit(EXIT_SUCCESS);
        }
        dfs(v);
    }

    estado[u] = 2;
    topo.PB(u);

}

void solve(){
    dfs(mapa[change]);

    reverse(all(topo));
    for(auto u: topo){
        cout<<mapaR[u]<<'\n';
    }
}


void read(){
    cin>>n;

    mapa.clear();
    mapaR.clear();
    topo.clear();
    FOR(i,1,n){
        adj[i].clear();
        estado[i] = 0;
    }

    //base: dependecies
    stringstream ss;
    string line;
    string b,d;


    getchar();

    int id = 1;
    FOR(i,1,n){

        getline(cin,line);
        ss.str(line);
        ss>>b;
        b.pop_back();
        // cout<<b<<" : ";

        if( mapa.find(b) == mapa.end()){
            mapa[b] = id;
            mapaR[id] = b;
            id++;
        } 

        while(ss>>d){
            // cout<<d<<' ';
            if( mapa.find(d) == mapa.end()){
                mapa[d] = id;
                mapaR[id] = d;
                id++;            
            }
            adj[mapa[d]].PB(mapa[b]);
        }
        // cout<<'\n';
        ss.clear();
    }

    cin>>change;

    // FOR(i,1,n){
    //     cout<<mapaR[i]<<" ";
    // }
    // cout<<'\n';

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
    solve();


    return 0;
}
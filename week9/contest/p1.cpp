/*

Complejidad algoritmoca O(2^v  .  v^2):

se recorre por todas las combinaciones posibles de vertices usadas (m) [ complejidad 2^v]

y por cada combinacione fijamos un vertice u de como vertice actual [complejidad v]

encontramos el minimo, explorando el costo para poder llegar a u
a traves de alguno de los vertices usados (alguno de los bits en 1) [complejidad v]

-> notar que el caso base, cuando m (1..1) es decir todos los vertices fueron usados, 
   la distancia de llegar entre u a v0

una vez terminado el proceso verificamos si existe una solucion valida o no.


complejidad espacial (  2^v  v)

int dp[N][ (1<<N)  + 1] :
-> i: la vertice actual  [N vertices]
-> j: el estado que representa las vertices usadas (bit 1) y no usadas (bit 0) [2^v suconjuntos de vertices]

int adj[N + 1][N + 1];
-> contenedor de distancias de un vertice i a un vertice j

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
const int N = 15;

int n,e;

int dp[N][ (1<<N)  + 1];
int adj[N + 1][N + 1];

void sol(){

    int v0 = 0;
    ROF(m, (1<<n) -1 , 0){

        FOR(u,0,n-1){
            
            if(m == (1<<n) -1 )  {
                dp[u][m] = adj[u][v0]; continue;
            }
            
            dp[u][m] = INF;

            FOR(op, 0 , n-1){
                if( (m & (1<<op)) == 0){
                    dp[u][m] = min(dp[u][m],  adj[u][op] + dp[op][m | (1<<op)]);
                }
            }
        }
    }


    if(dp[0][1] == INF) {
        cout<<"-1\n";
        return;
    }
    cout<<dp[0][1]<<'\n';

}



int main(int argc, char const *argv[]) {
    

    cin>>n>>e;



    FOR(i, 0, n){
        FOR(j, 0, n){
            adj[i][j] = INF;
        }    
    }

    int s,t,d;
    FOR(i, 1, e){
        cin>>s>>t>>d;
        adj[s][t] = d;
    }

    // FOR(i, 0, n){
    //     FOR(j, 0, n){
    //         if(adj[i][j] == INF) cout<<"INF ";
    //         else cout<<adj[i][j]<<" ";
    //     }    
    //     cout<<endl;
    // }

    sol();

    return 0;
}
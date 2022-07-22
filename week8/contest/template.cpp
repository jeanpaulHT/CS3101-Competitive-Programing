/*

Complejidad algorimica O(n* w):
    -n : numero de items
    -w : capacidad maxima de la mochila

    Se usa la solucion original de knacksack y luego se mantiene un historial de previos
    de los caminos tomados. Si se tomo un elemento nuevo se pone en el contenedor auxuliar 
    como previo a si mismo. Asi cuando llegamos a una posicion que se tiene a si mismo como previo,
    obtendremos a la solucion.

    
Complejidad espacial (n * w):

    Se tiene que guardar cada resultado del dp, es decir toas las combinaciones de
    i [1,i] y j[0,w]


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
const int N = 5e3+10;

const int max_int = ~(1<<31);

int dp[N][N];
int aux[N][N];

int v[N];
int w[N];
//F = num of items taken
//S.F = if current item was taken into the array
//S.S = previous item.


int W,n;

void sol(){

    
    aux[0][0] = 0;

    FOR(i, 1, n){
        

        FOR(j,1, W){            

            if(dp[i-1][j] > dp[i][j] ){
                dp[i][j] = dp[i-1][j];
                aux[i][j] = aux[i-1][j];
            }

            if(w[i] <= j && dp[i][j] <= dp[i-1][j - w[i]] + v[i]){
                
                dp[i][j] = dp[i-1][j - w[i]] + v[i];
                
                // si es el primer item tomado
                if(dp[i-1][j - w[i]] == 0 || aux[i-1][j] ){
                    aux[i][j] =  i;
                }
                else{
                    aux[i][j] = aux[i][j - w[i]] ;
                }
            }
        }

        // printf("(p%d:%d) [%d,%d],", i, dp[i][W], aux[i].F, aux[i].S);

    }
    cout<<'\n';




    FOR(i, 1, n){
        printf("p%d (%d) dp[%d],", i, aux[i][W], dp[i][W]);
    }
    

    int i = n;
    int z = W;
    while(i !=  aux[i][z]){
        cout<<i;

        z -= w[i];
        i = aux[i][z];    
    }

    cout<<'\n';

    // int i = n;

    // while(i != aux[i].S){
    //     if(aux[i].F) cout<<i<<" ";
    //     i = aux[i].S;
    // }

    // cout<<'\n';


    cout<<dp[n][W]<<'\n';
}


int main(int argc, char const *argv[]) {
    
    int t;

    
    while(cin>>W){
        cin>>n;

        FOR(i,1,n) cin>>v[i]>>w[i];
        memset(dp, 0,N*N );
        sol();
    }
   

    return 0;
}
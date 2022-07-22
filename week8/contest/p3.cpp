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
const int N = 5e6+10;

const int max_int = ~(1<<31);

int dp[N];

void sol(){
    
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
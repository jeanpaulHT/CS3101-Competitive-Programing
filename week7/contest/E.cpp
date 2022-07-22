// www.paginaPregunta.com

/*

Complejidad de tiempo = O(n . m):

donde n y m son los tamaños de los strins 1 y 2 respectivamente.
La idea de la solucion viene del concepto de distance para
covertir un string a otro con la menor cantidad de movimientos posibles
los movimientos son definidos como:

- add
- remove
- replace

cave notar que tomamos en cuenta los casos base cuando alguno de los strings es vacia
por lo que se necesitaria una cantidad de x movimientos (donde x es el tamaño del string 
vacio) para poder eliminar los caracteres del string no vacio.


Despues definimos los subproblemas dp[i][j] 
como:
convertir el string1 (desde 1 hasta i)
a el string 2 (desde 1 hasta j)

despues seguimos los movimientos para el DP definidos por el distance

    -delete dp[i-1][j] + 1, // delete letter i-1
    -add [i][j-1] + 1, //add letter j-1 
    -replace dp[i-1][j-1] + (str1[i-1] != str2[j-1]) 


Complejidad de espacio = O(n^2):
Se guarda una matrix para guardar los resultados del DP para todas las combinaciones
de i e j. (donde  0<=i <= n  , y   0<= j<=m)

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


string str1,str2;

int  t;


int dp[N][N];

void sol(){
    
    FOR(i,0,sz(str1)) dp[i][0] = i;
    FOR(j,0,sz(str2)) dp[0][j] = j;


    int m = 0;

    FOR(i , 1,sz(str1)){
        FOR(j,1,sz(str2)){

            dp[i][j] = INF;
            
            dp[i][j] = min({
                dp[i-1][j] + 1, // delete letter i-1
                dp[i][j-1] + 1, //add letter j-1
                dp[i-1][j-1] + (str1[i-1] != str2[j-1]) //replace 
            });
        }
        
        // FOR(z , 1, sz(str2) ){
        //     cout<<dp[i][z]<<" ";
        // }
        // cout<<'\n';
    }

    cout<<dp[sz(str1)] [sz(str2)]<<'\n';
}

int main(int argc, char const *argv[]) {
    

    cin>>t;


    FOR(tc,0,t-1){        
        cin>>str1>>str2;

        sol();
    }
    
    return 0;
}
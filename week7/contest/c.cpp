// www.paginaPregunta.com


/*

Complejidad de tiempo = O(n ^ 2):

El algoritmos es una implementacion de la idea
de maximum Subsequence Sum

el subproblema:

dp[i] : la sumatoria maxima de la subsecuencia que contenga al valor a[i]
        tal que todos los elementos sean < a[i]


para tomar el output deseado se toma en consideracion lo siguiente:
- todos los elementos en al subsecuencias son estrictamente menor a[i]
- si el subproblema tomando dp[j] esta en tie, se lo toma como resultado (esto es para mantener el orden lexografico)
- se toma el ultimo dp[i] que mayor o igual al  maximo global actual  (esto es para mantener el orden lexografico)


si algun dp[j] se  toma como resultante o maximo para a dp[i]. Se almacena el indice j como 
valor previo a i.

Esto sirve para despues recorre todos los valores previos del dp[] maximo  
y reconstruir la subsecuencias en aux.
Luego se recorre aux para imprimer el subsecuencia. 

Complejidad de espacio = O(n):

se guardan los siguientes arrays de tamaño n para:

-  a[] : almacenar los datos de input
- dp[] : almacenar los resultados de los subproblemas
- idx[] : almacena el indice del valor previo en el subarreglo
- aux[] : auxiliar para imprimir/almacenar los valores del subarreglo resultante

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


ll a[N];
ll dp[N];
ll idx[N];
ll aux[N];


int n;
int t;


void sol(){
    
    dp[0] = 1;
    idx[0] = 0;
    ll m  = 1;

    int ans = 0;

    FOR(i,1,n-1){

        dp[i] = 0;
        idx[i]  = i;

        FOR(j,0,i-1){
            
            if(a[j] < a[i] && dp[i]  <= dp[j]  ){
                idx[i] = j;
                dp[i] = dp[j];
            }
        }

        dp[i]++;


        if(dp[i] >= m){
            m = dp[i];
            ans = i;
        }
    }



    int i = ans;
    int it = 0;
    while(idx[i] != i){
        aux[it++] = a[i];
        i = idx[i]; 
    }
    aux[it] = a[i];
    
    cout<<m<<" ";
    ROF(z, it,0){
        cout<<aux[z]<<" ";
    }
    cout<<'\n';
    
}

int main(int argc, char const *argv[]) {
    
   
    while(cin>>n){
        if(n == 0) break;

        FOR(i,0,n-1) {
            cin>>a[i];
            // cout<<a[i]<<" ";    
        }
        // cout<<"|";
        sol();    
    }    

    return 0;
}
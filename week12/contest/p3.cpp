
/*

Complejidad algoritmica: O(tc * n^2)

tc: el numero de casos
n: n^2 toda la matris

por cada test case el algoritmo construye la matriz imagen (a) y luego 
recorre todo a hasta encontrar un '-', en cuyo caso aplica un algoritmo de
floodfill (que en el peor caso recorre toda la matriz O(n^2)) y suma en uno el numero de huecos.
Repite este proceso hasta recorrer toda a.

Esto funciona debido a que, una vez que encontremos un espacio en blanco o un '-' se sobrescribira todo
el espacio en blanco que esta conectado a '-' con el simbolo '#'. Por lo que se eleminara ese espacio en blanco. Por lo cual
aumentamos nuesstro contador de estrellas en 1. Basicamente encontremos una estrella y la sobrescrimos.

El floodfill al solo sobreescribir la estrella a la que pertence nos podemos asegurar que no sobrecontaremos.


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
const int N = 2e2+ 10;


char a[N][N];
int n,m,t;


bool fuera(int i, int j){
    return  (i <0 or j <0 or i>= n or j >= m);
}

void floodfill(int i, int j, char from, char to){

    if( fuera(i,j) or a[i][j] != from)  return;
    
    a[i][j] =  to;

    floodfill(i-1,j,from,to);
    floodfill(i,j-1,from,to);
    floodfill(i,j+1,from,to);
    floodfill(i+1,j,from,to);
}

void sol(){
    
    int contador = 0;

    FOR(i, 0, n-1){
        FOR(j,0,m-1){
            if(a[i][j] == '-'){
                floodfill(i,j,'-','#');
                contador++;
            }
        }
    }

    printf("Case %d: %d\n",t,contador);
}

int main(int argc, char const *argv[]) {


    // #ifndef ONLINE_JUDGE
    //     // For getting input from input.txt file
    //     freopen("in", "r", stdin);
    //     // Printing the Output to output.txt file
    //     freopen("out", "w", stdout);
    //     //Printing errors in out file
    //     freopen("out", "w", stderr);
    // #endif

    t = 1;
    while (cin>>n){
        cin>>m;


        memset(a,0,N*N *sizeof(char));
        FOR(i, 0, n-1){
            FOR(j,0,m-1){
                cin>>a[i][j];
            }
        }

        sol();
        t++;
        
    }
    

    

    return 0;
}
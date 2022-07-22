// www.paginaPregunta.com

/*********************************DOCUMENTACIÓN*********************************

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor

Complejidad de tiempo = O( n^2  lg n) 
Se hace un sort del arreglo (lg n)
Se revisa todas las combinaciones de palos posibles, y se encuentra la suma de esa combinacion for [for anillado]. 

Se hace una busqueda binaria con Upper bound para buscar al primer numero que sea mayor a la suma,
y se cuenta la distancia entre ese elemento encontrado y el final del arreglo (los palos con los cuales no se 
puede hacer triangulo)

Complejidad de espacio = O(n) 
con el espacio que se usa es n, para todos los posibles 2 * 10^3 arreglos que pueden venir como input

*******************************************************************************/

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
const int N = 2e6+10;

const int max_int = ~(1<<31);

int n;
vi arr(2000);
unordered_set<int> s;

int l_min = max_int;


void sol(){

    sort(arr.begin(), arr.begin() + n);

    int count = 0;

    FOR(i, 0, n-1){

        FOR(j, i+1, n-1){


            int sum = arr[i] + arr[j];

            auto f = upper_bound(arr.begin(), arr.begin() + n, sum );
            int c =  distance(f, arr.begin() + n);
            count += c;


        }

    }

    cout<<count<<'\n';

}

int main(int argc, char const *argv[]) {

    
    for(cin>>n; n != 0; cin>>n){


        FOR(i,0,n-1){
            cin>>arr[i];
        }

        sol();

        
    }
    
    return 0;
}
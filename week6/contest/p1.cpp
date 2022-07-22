// www.paginaPregunta.com

/*********************************DOCUMENTACIÓN*********************************

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor

Complejidad de tiempo = O(t n) con 

teniendo que hacer una busqueda lineal despues de ordenar los 2 arreglos (lg n)
para poder sacar el resultado del producto punto

Se minimza cada  producto al juntar el i elemento mas grande con el i elemento menor
para el producto de ambos  

Complejidad de espacio = O(n) con 
2 arrays que guardan los n numeros para el vector x e y

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


vll x(800);
vll y(800);

ll t,n;

ll local_t;

void sol(){

    sort(x.begin(), x.begin() + n);
    sort(y.begin(), y.begin() + n, [](ll &p1,ll&p2){return p1 > p2;} );
    
    // FOR(i,0,n-1) cout<<x[i]<<" ";
    // cout<<'\n';
    // FOR(i,0,n-1) cout<<y[i]<<" ";
    // cout<<'\n';

    ll res = 0;


    int p1  = 0;
    int  p2 = n-1;
    FOR(i , 0 , n-1){
        ll temp ;
        
        temp = (x[i] * y[i]);

        // cout<<temp<<'\n';
        res += temp;
    }

    printf("Case #%lld: %lld\n", local_t , res);

}

int main(int argc, char const *argv[]) {

    cin>>t;

    for(local_t = 1; local_t <= t; local_t++){
        cin>>n;
        FOR(i,0,n-1) cin>>x[i];
        FOR(i,0,n-1) cin>>y[i];

        sol();
    }

    return 0;
}



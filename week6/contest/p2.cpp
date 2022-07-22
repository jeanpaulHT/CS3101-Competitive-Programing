

// Complejidad de tiempo = O(n) con 
// Se ordena los valores del arr  (n log n) y luego se recorren estos.
// Decimos que el fairness  de un sub arreglo k es la distancia entre
// el primer elemento del subarreglo y el ultimo.
// Se recorre todo el arr ordenado hallando el minimo fairness de los subarreglos.

// Complejidad de espacio = O(n) con 
// un array de tamaño n para contener a todos los vallores que del arr

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


int arr[N];
int n,k;


int main(int argc, char const *argv[]) {

    cin>>n>>k;
    
    FOR(i,0,n-1){
        cin>>arr[i];
    }

    sort(arr , arr + n);

    int lmin  = INF;
    FOR(i , 0 , n-k){
        int a = arr[i+k-1] - arr[i];
        lmin = min(a,lmin);
    }
    
    cout<<lmin;
    return 0;
}
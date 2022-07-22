
/*


Complejidad de tiempo = O(log n) con  = se hace una simple busqueda binaria para buscar la primera y ultima ocurrencia del
la k, usando lower y uper bound. Despues solo se revisa si se encontre alguna ocurrencia y se devuelve el output correspondido
Complejidad de espacio = O(n) con = 
vector  de size n para almacenar los n numeros

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
const int N = 2e6+10;

const int max_int = ~(1<<31);

int n,k;
vector<int> arr;





void sol(){

    int f = lower_bound(all(arr),k) - arr.begin();
    int l = upper_bound(all(arr),k) - arr.begin();



    if(f == n || arr[f] != k ){
        cout<<"-1 -1 0";
        return ;
    }
    
    cout<<f<<" "<<l-1<<" "<<l-f;
    
    
}




int main(int argc, char const *argv[]) {

    cin>>n;
    arr.resize(n);
    FOR(i,0,n-1){
        cin>>arr[i];
    }
    cin>>k;

    sol();
    
    return 0;
}
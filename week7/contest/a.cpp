/*Complejidad de tiempo = O(n ):

El algoritmos es una implementacion de la idea
de dynamic programming para encontrar el maximum sum subarray

el subproblema:

dp[i] : la sumatoria maxima del subarreglo  que contenga al valor a[i]

se aplica la logica tal que

dp[i] =  max(dp[i-1] + a[i], a[i]);

para decidis si ellemento de i inicia un nuevo subarreglo, o es continuacon del anterior.

Se toma el dp[] maximo como repuesta.

para hallar la subsecuencia de suma maxima se implementa la siguiente logica:

- se suman todos los elementos positivos (sum)
- se almacena el elemento maximo del arreglo (me)

si la suma de positivos es mayor a 0. Se toma este como resultado (sum)
caso contrario, significa que el arreglo es de negativos. Asi que se toma como
resultado al mayor valor de estos negativos (me)



Complejidad de espacio = O(n):

se guardan los siguientes arrays de tamano n para:

-  a[] : almacenar los datos de input
- dp[] : almacenar los resultados de los subproblemas

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
const int N = 5e5+10;

const int max_int = ~(1<<31);


ll dp[N];
ll a[N];

int n;

void sol(){
    
    //maximum subsequence variables (stuff)
    ll me = a[0]; //maximum element
    ll sum = (a[0] > 0) ? a[0] : 0;  //sum of positive integers


    // dp variable (stuff)
    dp[0]  = a[0];
    ll m = a[0];
    FOR(i, 1, n-1){
        
        // maximum subsequence stuff
        me = max(me, a[i]);
        sum += (a[i] > 0) ? a[i] : 0;
        
        //start of dp [maximum sur array]
        dp[i] = max(dp[i-1] + a[i] , a[i]);
        m = max(m, dp[i]);
        //end 
    }




    ll ans_sub;

    if(sum > 0) ans_sub = sum;
    else ans_sub = me;

    cout<<m<<" "<<ans_sub<<'\n';
    
}


int main(int argc, char const *argv[]) {


    int t ;

    cin>>t;

    FOR(tc,0,t-1){
        cin>>n;
        // cout<<"array:";
        FOR(i,0,n-1){
            cin>>a[i];
            // cout<<a[i]<<" ";
        }
        // cout<<'\n';
        sol();
    }


    return 0;
}
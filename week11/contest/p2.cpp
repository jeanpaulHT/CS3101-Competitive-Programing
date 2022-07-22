/*

complejidad algoritmoca:

O(tc * (m))


se arma el array de pi, entonces. una vez teniendo estos
sabemos que el el valor pi[m-1] que seria el valor final
del array de pi seria de los valor al cual podemos regresar si
encontramos un mitmatch

lo cual significa que 
m - pi[m-1] seria los caracteres que se necesitarian para poder
hahcer las repeticiones de la cadena
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
const int N = 1e6+10;


ll pi[N],n,m,k,q;
ll res[N];

string t,p,h;

void build(){
    
    n = sz(t);
    m = sz(p);

    
    pi[0] = 0;
    k = 0;
    m = sz(p);
    FOR(q,1,m-1){
        while(k > 0 && p[q] != p[k])
        k = pi[k-1];
        
        if(p[k] == p[q]) k++;
        pi[q] = k;
    }
}

ll solve(){

    n = sz(t);
    m = sz(p);

    ll ans = 0;
    ll q = 0;

    FOR(i, 0, n-1){
        
        while(q > 0 && p[q] != t[i]) return 0;

        if(p[q] == t[i]) q++;
        
        if(q == m){
            ans++;
            q = 0;
        }
    }

    return ans;
}

int main(int argc, char const *argv[]) {


    #ifndef ONLINE_JUDGE
        // For getting input from input.txt file
        freopen("in", "r", stdin);
        // Printing the Output to output.txt file
        freopen("out", "w", stdout);
        //Printing errors in out file
        freopen("out", "w", stderr);
    #endif

    ll tc;

    cin>>tc;

    cin.ignore();

    while(tc--){
        
        getline(cin,t);



        p = h = t;
        build();



        cout<<m - pi[m-1]<<'\n';



        // cout<<t<<'\n';
        // FOR(i , 0, n-1) cout<<i<<":"<<pi[i]<<"\n";
        // cout<<'\n';

        // solve();
    }
    

    return 0;
}
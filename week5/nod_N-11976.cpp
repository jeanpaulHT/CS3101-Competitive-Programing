// www.paginaPregunta.com

/*********************************DOCUMENTACIÓN*********************************

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor

Complejidad de tiempo = O(*) con *=?
Complejidad de espacio = O(*) con *=?

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
const int N = 2e6 + 1;
const int n_nod= 1e6+1;


int divisors[N + 1];

int nod[N + 1];


void divisor_siev(){
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; j += i)
    ++divisors[j];

}

void prec_nod(){

    nod[1] = 1;
    nod[0] = 0;

    for(int i = 2; i < n_nod ; i ++){
        nod[i] = nod[i-1] + divisors[nod[i-1]];
    }
    
}


int main(int argc, char const *argv[]) {    

    divisor_siev();
    prec_nod();

    int t,a,b;

    cin>>t;
    FOR(i,1,t){
        cin>>a>>b;
        auto f = std::lower_bound(nod + 1, nod + n_nod, a);
        auto l = std::upper_bound(nod + 1, nod + n_nod, b);

        int res = distance(f,l);
        cout<<"Case "<<i<<": "<< res<<'\n'; 
    }
    
    
    return 0;
}
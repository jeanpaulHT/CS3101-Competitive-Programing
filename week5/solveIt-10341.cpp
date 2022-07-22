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
const int N = 2e6+10;


double ec_p,ec_q,r,s,t,u;

double f(double x){
    
    return ec_p * exp(-x) + ec_q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

void sol(){
    double p,q,r;
    p = 0;
    q = 1;
    double esol;
    FOR(i,0,20){
        r = (p+q)/2;
        if( f(r) > 0) p = r;
        else q = r;
    
    }

    if(f(r) <= 1e-4){
        printf("%0.4f", r);
    }
    else{
        cout<<"No solution\n";
    }
}

int main(int argc, char const *argv[]) {


    cin>>ec_p>>ec_q>>r>>s>>t>>u;
    sol();
    
    return 0;
}
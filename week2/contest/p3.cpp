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

int n,m;


void sol(){
    int ans = 0;
    FOR(k, 1, m){
        int sw,t;
        cin>>sw;
        FOR(p,1,sw){
            cin>>t;
            if(ans >> (t-1) & 1)
            ans = ans & (  1 << (t-1)) ; 
        }
    }
}

int main(int argc, char const *argv[]) {
    cin>>n>>m;


    return 0;
}
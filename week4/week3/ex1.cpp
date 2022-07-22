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


int n;
vi s;
bool flag = 1;
bool b[18] {};

void generar(int i){
    if(i ==n){
        for(int s_i: s)cout<<s_i;
        cout<<endl;
    }
    else{

        s.PB(b[i]); 
        generar(i+1);
        s.pop_back();
        s.PB(!b[i]); 
        generar(i+1);
        s.pop_back();
        b[i] = !b[i];
    }
}

int main(int argc, char const *argv[]) {
    cin>>n;
    generar(0);
    return 0;
}
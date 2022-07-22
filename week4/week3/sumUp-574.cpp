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


const int N = 40;
bool vis[N] ;

int n;
vi num;
vi s;
set<vector<int>> st;

void generar(int i,int pos){

    if(i == n){
        st.insert(s);
        return;
    }
        
    for(int j = pos; j < sz(num);j++){

        if(i + num[j] <= n ){
            s.PB(num[j]);
            generar(i+num[j],pos+1);
            s.pop_back();
        }
    }
}

int main(int argc, char const *argv[]) {
    
    n = 4;
    num = {6,4,3,2,2,1,1};
    generar(0,0);
    for(auto v: st){
        for(auto p: v){
            cout<<p<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
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

int k,d;


int l;

int pos_height(int l_h, int l_k){

    int p = 0;
    int q = pow(2,l_h-1) - 1;

    while(p < q){
        int r = (p+q)/2;
        

        if( l_k %2 == 0 ){
            p = r + 1;
            l_k /= 2;
        }
        else{
            q = r;
            l_k = l_k/2 + 1;
        } 

    }

    // cout<<q;
    return q;   
}


void sol(){

    int local_h = d;
    int local_k = k;
    
    // if local level is full
    while (local_k > pow(2, local_h - 1)){
        local_k -= pow(2, local_h - 1);
        local_h--; 
    }
    
    int offset = pow(2, local_h-1);

    cout << pos_height(local_h, local_k) +  offset<<'\n';

}

int main(int argc, char const *argv[]) {
    
    cin >>l;

    while (l--){
        cin>>d>>k;
        sol();
    }
    
    
    
    return 0;
}
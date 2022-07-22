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



bool inline is_pair(int x){
    return x % 2 == 0;
}




int main(int argc, char const *argv[]) {
    int t,a,b;
    cin>>t;

    FOR(i,1,t){
        cin>>a>>b;
        
        if( (!a || !b) || (is_pair(a) && is_pair(b) ) || abs(a - b) > 2 ){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    

}
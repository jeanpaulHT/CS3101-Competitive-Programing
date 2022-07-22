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


int get_upper_sqrt(int n){
    double res = sqrt(n);
    int conv = (int) res;
    if(res > conv){
        return conv + 1;
    }
    return conv;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;

    FOR(t,1,n){
        string msg;
        cin>>msg;
        int m = get_upper_sqrt(sz(msg));
        int size = m*m;
        // just pb
        while(sz(msg) < size ){
            msg.push_back('*');
        }
        for(int j = 0; j < m; j++){
            int posy = j;
            for(int k = m-1; k >= 0 ;k--){
                int posx = k*m;
                int pos = posx+posy;
                if(msg[pos] == '*') continue;
                else cout<<msg[pos];
                
            }
        }
        cout<<'\n';

        
    }
    return 0;
}
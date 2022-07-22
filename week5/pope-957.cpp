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


int y,p;
vi popes;

void sol(){
    int max_pope = -INF;
    int first, last;

    FOR(i, 0, p-1){
        int cur_y = popes[i];
        auto f = std::lower_bound(all(popes), cur_y);
        auto l = std::lower_bound(all(popes), cur_y  + y);
        

        int num_popes = distance(f,l);

        if(num_popes > max_pope){
            first = *f;
            last = *(l-1);
            max_pope = num_popes;
        }
    }

    cout<<max_pope<<" "<<first<<" "<<last<<'\n';

}

int main(int argc, char const *argv[]) {    

    cin>>y>>p;
    popes.resize(p);

    FOR(i,0,p-1){
        cin>>popes[i];
    }

    for(auto it: popes){
        cout<<it<<" ";
    }
    cout<<endl;
    sol();
    
    return 0;
}
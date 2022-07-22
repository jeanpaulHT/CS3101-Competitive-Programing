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

#define INF (1<<30)

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




int n,m,t;
vector<vi> h;

int r1,r2;
string str, q;


int f,l;

void sol(){

    int local_f,local_l, local_size;
    int size = 0;

    
    FOR(i, 0, n-1){
        auto i1 = upper_bound(h[i].begin(), h[i].end(), r1-1);
        local_l = distance(h[i].begin(), i1);

        // cout<<'\n'<<local_l<<" ";

        
        local_size = 0;
        FOR(j, local_l , m-1){
            if(i +  local_size >= n) break;
            if( h[i + local_size][j] > r2) break;
            local_size++;
        }
        // cout<<"size:"<<local_size;
        size = max(size, local_size);    
    }
    // cout<<'\n';

    cout<<size;

    cout<<endl;

}

int main(int argc, char const *argv[]) {
    
    while( cin>>n>>m ){
        if(n == 0 || m == 0) break;

        FOR(i , 0, n-1){
            h.PB(std::vector<int> (m));
            FOR(j,0, m-1){
                cin>>h[i][j];
            }
        }

        cin>>t;

        FOR(i,0, t-1){
            cin>>r1>>r2;
            sol();
        }
        cout<<"-\n";
        h.clear();
    }
    return 0;
}
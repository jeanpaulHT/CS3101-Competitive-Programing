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
vector<vi> diag;

int r1,r2;
string str, q;


int f,l;


void print(){

    for(auto d: diag){
        for(auto i: d){
            cout<<i<<' ';
        }
        cout<<'\n';
    }
}

void sol(){

    int local_f,local_l, local_size;
    int size = 0;

    
    for(auto d: diag){
        auto it_low = upper_bound(d.begin(), d.end(), r1 - 1);
        local_f = distance(d.begin(), it_low);

        auto it_up = upper_bound(d.begin(), d.end(), r2);
        local_l = distance(d.begin(), it_up);

        size = max(size , local_l - local_f);
    }
    cout<<size<<'\n';

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

        int diag_cnt = 0;
        for(int i = n-1; i >= 0; i--){
            int temp = i;
            diag.PB(vi() );

            FOR(j, 0 , diag_cnt){
                diag[diag_cnt].PB(h[temp++][j]);
            }
            diag_cnt++;
        }


        int temp_diag = diag_cnt;
        FOR(j, n - temp_diag + 1 , m-1){
           int temp = j;
           diag.PB(vi());
           FOR(i, 0, temp_diag-1){
               diag[diag_cnt].PB(h[i][temp++]);
           }
           temp_diag--;
           diag_cnt++;
        }


        FOR(i,0, t-1){
            cin>>r1>>r2;
            sol();
        }
        cout<<"-\n";
        h.clear();
        diag.clear();
    }
    return 0;
}
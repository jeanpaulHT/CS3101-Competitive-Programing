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
const int N = 100;

const int max_int = ~(1<<31);

int n, a[N][N], dp[N][N], aux[N];



void solve(){
    int ans = 0;

    FOR(l,0,n-1){

        FOR(r , l , n -1){

            FOR(i,0,n-1){
                aux[i] = dp[i][r];
                if( i>0) aux[i] -= dp[i][l-1];
            }

            //Kadame
            int s,m;
            s = m = 0;
            FOR(i,0,n-1){
                s+= aux[i];
                if(s < 0)  s = 0;
                m = max(m,s);
            }

            ans = max(ans,m);
        }
    }

    cout<<ans<<endl;
}


void preproc(){
    FOR(i,0,n-1){
        FOR(j,0,n-1){
            dp[i][j] = a[i][j];
            if(j> 0) dp[i][j] += dp[i][j-1];
        }
    }
}

int main(int argc, char const *argv[]) {

    return 0;
}
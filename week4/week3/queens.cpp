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


#define n 8

#define N 100

bool col[N] {};
bool diag1[N] {};
bool diag2[N] {};
bool res[N][N] = {0,0};

int ans = 0;

void generar(int y){
    if(y == n){
        ans++;
        return;
    }
    FOR(x,0,n-1){
        if(col[x]|| diag1[x+y] || diag2[x-y+n-1]) continue;
        if(res[x][y]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] =1;
        generar(y+1);
        col[x] = diag1[x+y] = diag2[x-y+n-1] =0;
    }
}

void input(){
    
    char r;
    FOR(i,0,n-1){
        FOR(j,0,n-1){
            cin >> r;
            if(r == '*') res[i][j] = 1;
            else res[i][j] = 0;
        }
    }
}
int main(int argc, char const *argv[]) {
    input();
    generar(0);
    cout<<ans;
    return 0;
}
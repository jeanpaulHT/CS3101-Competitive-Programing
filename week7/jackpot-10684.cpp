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

const int max_int = ~(1<<31);

int b,r;
int n,t;

int a[N];
int dp[N];


void sol(){

    dp[1] = a[1];

    int ans = 0;

    FOR(i,2,n){
        dp[i] = max(a[i], dp[i-1] + a[i]);

        ans = max(ans, dp[i]);
    }    

    if(ans > 0){
        printf("The maximum winning streak is %d.\n", ans);
    }
    else{
        printf("Losing streak.\n");
    }
}

int main(int argc, char const *argv[]) {
    
    while(cin>>n){
        if(n == 0) break;

        FOR(i,1,n) cin>>a[i];
        
        sol();
    }

    return 0;
}
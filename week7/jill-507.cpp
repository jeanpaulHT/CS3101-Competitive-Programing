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
int n;
int t;

int a[N];
pair<int,int> dp[N];


void sol(){

    ll ans = a[1];
    int fin,ini;

    dp[1].F = 1;
    dp[1].S = a[1];

    fin = ini  = 1;
    FOR(i,1,n-1){
        
        if(a[i] > dp[i-1].S + a[i]){
            dp[i].F = i;
            dp[i].S = a[i];
        }
        else{
            dp[i].F = dp[i-1].F;
            dp[i].S = dp[i-1].S + a[i];
            
        }

        
        if( (dp[i].S > ans) || (dp[i].S == ans && (i-dp[i].F > fin-ini) ) ){
            ans = dp[i].S;
            fin = i;
            ini = dp[i].F;
        }


        printf("i = %d:dp = %d |  (%d,%d) [%d]\n", i,dp[i].S, dp[i].F, i,  a[i]);
    }
    
    
    
    if(ans >= 0) printf("The nicest part of route %d is between stops %d and %d\n",t,ini,fin+1);
    else printf("Route %d has no nice parts\n",t);

}

int main(int argc, char const *argv[]) {

    cin>>b;

    for(t = 1;t <= b;t++){
        cin>>r;
        n = r;

        FOR(i,1,n-1) {cin>>a[i];} 

        sol();
    }

    return 0;
}
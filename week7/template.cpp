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
int t = 1;

int arr[N];
int dp[N];


void sol(){
    
    dp[0] = arr[1];
    int res_i = 1,res_j = 1;

    FOR(i,1,n-1){
        
        if(arr[i] > dp[i-1] + arr[i]){
            dp[i] = arr[i];
            res_i = res_j = i;
        }
        else{
            dp[i] = dp[i-1] + arr[i];
            res_j = i; 
        }
    }

    if(dp[n-1] < 0){
        printf("Route %d has no nice parts\n",t);
    }
    else{
        printf("The nicest part of route %d is between stops %d and %d\n",t,res_i,res_j);
    }

}

int main(int argc, char const *argv[]) {

    cin>>b;
    cout<<b;
    for(;t <= b;t++){
        cin>>r;
        n = r;
        arr[0] = t;

        FOR(i,1,r-1) cin>>arr[i]; 

        sol();
    }

    return 0;
}
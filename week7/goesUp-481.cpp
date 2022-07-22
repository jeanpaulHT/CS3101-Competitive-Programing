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

int n;
int a[N];
int dp[N], idx[N], aux[N];

void sol(){

    
    int m = 1;
    int i_ans = 0;
    
    dp[0] = 1;
    idx[0] = 0;

    FOR(i,1,n-1){
        
        dp[i] = 0;
        idx[i] = i;
        FOR(j,0,i - 1){
            
            if(a[j] < a[i] && dp[j] >= dp[i]){
                idx[i] = j;
                dp[i] = dp[j] ; 
            }
        }

        dp[i]++;
        if(dp[i] >= m){
            m = dp[i];
            i_ans = i;
        }
    }
    

    int i = i_ans;
    int it = 0;

    
    while(idx[i] != i){
        aux[it++] = a[i];
        i = idx[i];
    }
    aux[it] = a[i];
    

    cout<<m<<"\n-\n";
    ROF(j, it, 0){
        cout<<aux[j]<<'\n';
    }

}

int main(int argc, char const *argv[]) {

    n = 0;
    int temp;
    while(cin>>temp){
        a[n++] = temp;
    }

    sol();



    return 0;
}
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

constexpr int INF = 1e9+10;
constexpr int N = 5e3+10;

const int max_int = ~(1<<31);

string str1,str2;

int dp[N][N];


void sol(){

    int m = 0;

    FOR(i,0,sz(str1)) dp[i][0] = i;
    FOR(j,0,sz(str2)) dp[0][j] = j;
    

    FOR(i,1,sz(str1) ){
        FOR(j,1,sz(str2) ){

            dp[i][j] = INF;

            dp[i][j] = min({
                dp[i-1][j-1] + (str1[i-1] != str2[j-1]), // replace
                dp[i-1][j] + 1, // delete letter i - 1
                dp[i][j-1] + 1  // add letter j - 1
            });
            
            m = max(m, dp[i][j]);
        }

        FOR(z , 1, sz(str2) ){
            cout<<dp[i][z]<<" ";
        }
        cout<<'\n';
    }

    cout<<dp[sz(str1) - 1 ][sz(str2) - 1];
}


int main(int argc, char const *argv[]) {

    cin>>str1>>str2;

    cout<<str1<<"\n"<<str2<<'\n';

    cout<<sz(str1)<<'\n'<<sz(str2)<<'\n';
    sol();
    return 0;
}
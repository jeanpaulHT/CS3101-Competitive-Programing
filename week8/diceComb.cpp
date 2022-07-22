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
const int N = 5e6+10;

const int max_int = ~(1<<31);

int n;

int dp[N];


void sol(){

    dp[0] = 0;
    FOR(i ,1,n){
        
        string num = to_string(i);
        for(auto c: num){
            dp[i] = min(dp[i], dp[i - (c - '0')] + 1);
        }

    }
    cout<<dp[n]<<'\n';
}

int main(int argc, char const *argv[]) {
    cin>>n;

    sol();
    return 0;
}
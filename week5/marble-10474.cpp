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



int n,q,a[N],x;

int main(){
    cin >> n >> q;
    FOR(i,0,n-1) cin >> a[i];
    sort(a,a+n);
    FOR(i,0,q-1) {
        cin >> x;
        auto it = lower_bound(a,a+n,x);
        printf((it==end(a) or *it!=x)? "%d not found\n" : "%d found at %ld\n", x, (it - a + 1));
    } 
    return 0;
}
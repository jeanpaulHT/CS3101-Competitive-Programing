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



int n,d,r;


int day[100];
int night[100];

void sol(){
    
    ll overtime =0;
    FOR(i , 0, n-1){
        int work_time = day[i] + night[ n - 1 - i];

        if(work_time > d){
            overtime += (work_time - d);
        }
    }
    
    printf("%lld\n", overtime *r);
}


int main(int argc, char const *argv[]) {
    
    while(cin >>n>>d>>r){
        if(n == 0) break;

        FOR(i, 0, n-1) cin>>day[i];
        FOR(i,0,n-1) cin>>night[i];

        sort(day , day + n);
        sort(night , night + n);

        sol();
    }




    return 0;
}
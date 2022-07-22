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


const int N = 40;
bool vis[N] ;

int  n;
vb prime;
vi s;


vector <bool> sieve (int n) {
  vector <bool> is_prime(n, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < n; i++) {
    if (!is_prime[i]) continue;
    for (int j = i + i; j < n; j += i) {
      is_prime[j] = false;
    }
  }
  return is_prime;
}

void generar(int i){

    if(i == n){
        if(prime[s[0] + s[n-1]] == false) return;
        for(int s1: s) cout<<s1<<" ";
        cout<<endl;
        return;
    }
        
    FOR(j, 2, n){
        if(vis[j]) continue;

        if(prime[j +s[i-1]] ){
            
            s.PB(j);
            vis[j] = 1;

            generar(i + 1);
            
            s.pop_back();
            vis[j] = 0;
        }
    }
}

int main(int argc, char const *argv[]) {
    
    prime = sieve(N);

    // for(int i = 0; i < N ;i++){
    //     if(prime[i])cout<<i<<" ";
    // }

    n = 8;
    vis[1] = true;
    vis[0] = true;
    s.PB(1);
    generar(1);

    return 0;
}
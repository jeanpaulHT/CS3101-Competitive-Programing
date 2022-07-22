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

int main(int argc, char const *argv[]) {
    ll n;
    ll sum, suml = 0, sumr = 0;
    cin>>n;
    sum = n * (n+1) / 2;

    if(sum % 2 ) {cout<<"NO";return 0;}
    sum /=2;

    vi l;
    vi r;

    vi p(2);
    for(int i = 1; i <= n/2; i++){
        p[1] = i;
        p[0] = n - i + 1;
        for(int j = 0; j < 2; j++){
            if(suml < sum){
                suml += p[j];
                l.push_back(p[j]);
            }
            else{
                sumr += p[j];
                r.push_back(p[j]);
            }

        }
    }
    if(n/2  + n/2 != n){
        sumr += (n/2 + 1);
        r.push_back(n/2 + 1);
    }

    
    if(suml != sumr) { cout<<"NO"; return 0;}
    else cout<<"YES\n";

    cout<<sz(l)<<'\n';
    for(auto it: l){
        cout<<it<<" ";
    }
    cout<<'\n'<<sz(r)<<'\n';
    for(auto it: r){
        cout<<it<<" ";
    }
    

}
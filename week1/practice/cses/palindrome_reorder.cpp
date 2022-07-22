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
    string str;
    cin>>str;
    sort(all(str));
    int n = sz(str);

    string res(n,' ');
    vector<char> vs;

    int ignore = 0;
    for(int i = 0; i < n/2 && ignore <= n/2; i++){
        int offset = 2*i + ignore;
        if(str[offset] != str[offset + 1]){
            vs.push_back(str[offset]);
            ignore++;
            i--;
            continue;
        }
        res[i] = str[offset];
        res[n - i - 1] = str[offset + 1];
        
    }

    if(n % 2){
        if(vs.empty()) res[n/2] = str.back();
        else{
            res[n/2] = vs[0];
            vs.erase(vs.begin());
        }
    }

    if(sz(vs) > 0) cout<<"NO SOLUTION";
    else cout<<res;
}
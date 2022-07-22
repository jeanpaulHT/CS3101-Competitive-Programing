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
    int w,p;
    cin>>w>>p;
    vi arr(p+2);
    arr[0]  = 0;
    FOR(i,1,p){
        cin>>arr[i];
    }
    arr[p+1] = w; 

    vi space(p+1);
    int prev,cur;

    FOR(i,1,p+1){
        prev = arr[i-1];
        cur = arr[i];
        space[i-1] = abs(cur - prev);
    }

    set<int> s;

    FOR(i, 1, p+1){
        int sum = 0;
        FOR(j,1,sz(space)){    
            //sum
            sum = 0;
            for(int k = j-1; k < j+i-1;k++){
                if(k >= sz(space)){sum = 0; break;}
                sum+= space[k];
            }
            // cout<<'\n';
            s.insert(sum);
        }
    }
    
    for(auto it: s){
        if(it==0) continue;
        cout<<it<<' ';
    }


    return 0;
}
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



int n,l,w;
vector<pair<float, float>> arr;
vector<pair<float, float>> s;

int k;

void sol(){
    int ans = 0;
    float last = 0.0;

    int i = 0;
    bool ok;
    while(last < l){
        ok  =  false;
        double temp_last  = last;

        printf("%f \n", last);

        while(i < k){
            if(s[i].F > last) break;
            if(s[i].S >= temp_last){
                temp_last = s[i].S;
                ok = true;   
            }
            i++;
        }
        if(!ok) break;
        ans++;
        last =temp_last;
    }

    if(!ok) printf("-1\n");
    else printf("%d\n",ans);
    
}


int main(int argc, char const *argv[]) {
    
    while(cin>>n>>l>>w){
        
        arr.resize(n);

        FOR(i,0,n-1){
            int a,b;
            cin>>a>>b;
            arr[i] = {a,b};
        }

        k = 0;
        FOR(i,0,n-1){
            pii p = arr[i];

            if(p.S <= w/2) continue;

            auto d = sqrt( p.S * p.S - w*w /4);
            
            s.PB({p.F -d , p.F + d});
            k++;
        }

        sort(all(s),  [] (const pii &p1, const pii &p2){return p1.F < p2.F;} );


        sol();

        s.clear();
        
    }

    return 0;
}
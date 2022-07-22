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
    int x,y;
    cin>>x>>y;
    int x1=0,x2=0,y1=0,y2=0;

    int dist = abs(x) + abs(y);
    if(x < 0 && y > 0 ){
        x1 = -dist;
        y2 = dist;
    }
    else if(x>0 && y >0 ){
        y1 = dist;
        x2 = dist;
    }
    else if(x < 0 && y < 0){
        x1 = -dist;
        y2 = -dist;
    }
    else if(x>0 && y<0){
        y1 = -dist;
        x2 = dist;
    }

    cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2;
    
    return 0;
}

//hola c:
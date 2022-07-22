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



int n;
vector<pii> arr;


void sol(){

    int max_arr = 1;
    int cur_arrival_end = arr[0].S;
    
    FOR(i , 1, n-1){

        pii ct = arr[i];
        
        if(cur_arrival_end < arr[i].F) {
            max_arr++;
            cur_arrival_end = arr[i].S;
        }

        
    }
    printf("%d\n", max_arr);
}


int main(int argc, char const *argv[]) {

    cin>>n;

    FOR(i,0,n-1){
        int a,b;
        cin>>a>>b;
        arr.PB({a,b});
    }

    sort(all(arr),  [] (pii &p1, pii &p2){return p1.second < p2.second;}
    );

    // for(auto p: arr){
    //     cout<<"("<<p.F<<" "<<p.S<<")\n";
    // }

    sol();



    return 0;
}
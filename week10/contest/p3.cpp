/*


Complejidad algoritmoca ():

el segmentr tree guarda 2 valores, el valor de la suma maxima de un sub array
entre x,y. [q.F]
Y la suma de todo el subarray que va desde x hasta y
[q.S]

se hace una seleccion en q1 y q2;
    - elegir q1.F
    - elegir q2.F
    - q1.F + q2.F
    - q1.S + q2.S






*/

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
const int N = 1e5+10;

const int max_int = ~(1<<31);



#define left(x) (x<<1)
#define right(x) (x<<1) + 1

int  A[N];
pair<int, pii> st[4 *N];


void build(int p, int L, int R){

    if(L == R) {
        st[p].F =  st[p].S.F =  st[p].S.S = A[L];
        return ;
    }
    int m = (L + R) / 2;
    
    build(left(p), L, m);
    build(right(p), m+ 1, R);
    
    st[p].F = max(st[left(p)].F , st[right(p)].F );
    st[p].S.F = st[left(p)].S.F;
    st[p].S.F = st[right(p)].S.S;
    

    if(st[p].F <  st[left(p)].S.S + st[right(p)].S.F){    
        st[p].F = max(st[p].F, st[left(p)].S.S + st[right(p)].S.F);
    }

    if(st[left(p)].S.F <  st[left(p)].S.F + st[right(p)].S.F){

    }
}


// int query(int p, int L, int R, int i, int j){

//     if(R <i || L > j) return 0;

//     if(L >= i &&  R <= j) return st[p];

//     int m = (L + R) / 2;
//     int q1  = query(left(p),    L,  m, i, j);
//     int q2  = query(right(p), m+ 1, R, i, j);
    
//     return  q1 + q2;
// }


int main(int argc, char const *argv[]) {


    #ifndef ONLINE_JUDGE
        // For getting input from input.txt file
        freopen("in", "r", stdin);
        // Printing the Output to output.txt file
        freopen("out", "w", stdout);
        //Printing errors in out file
    #endif

    int t,n,q,a,b,c;

    cin>>t;
    FOR(tc, 1, t){

        
        cin>>n>>q;
        FOR(i,1,n) cin>>A[i];

        build(1,1,n);

        // cout<<"A:";
        // FOR(i,1,n) cout<<A[i]<<" ";
        // cout<<"\n";


        // cout<<"st:";
        // FOR(i,1,2*n) cout<<st[i]<<" ";
        // cout<<"\n";

        printf("Case %d:\n",tc);
        while(q--){
            cin>>c;


        }
    }
    return 0;
}
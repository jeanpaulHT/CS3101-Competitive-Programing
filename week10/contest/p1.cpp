
/*
Complejidad algoritmica:
O(T (n + q lg n) )

T: es el numero de tests
n: es el numero de enteros de input
q: es el numero de queries que se hace en cada test

Por cada test O(T) se hace lo siguientes: 

- se crear un segment tree [build], cuya recursion es T(2 T(n/2)) por lo que su
    comlejidad es O(n)

- despues por cada query O(q) se hace lo siguiente:
    - se llama  a la funcion query la cual es O(lg n)


La idea del programa es correr un minquery, por lo que en el
segment tree guardamos los valores minimos de un rango [L,R]

Complejidad espacial:

A[N]: guarda los n valores de input
st[N]: guarda los  valores del segment tree

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
const int N = 2e5+10;

const int max_int = ~(1<<31);



#define left(x) (x<<1)
#define right(x) (x<<1) + 1


int A[N];
int st[4 *N];


void build(int p, int L, int R){

    if(L == R) {
        st[p] = A[L];
        return ;
    }
    int m = (L + R) / 2;
    
    build(left(p), L, m);
    build(right(p), m+ 1, R);
    
    st[p] = min( st[left(p)], st[right(p)]);
    
}


int query(int p, int L, int R, int i, int j){

    if(R <i || L > j) return INF;

    if(L >= i &&  R <= j) return st[p];

    int m = (L + R) / 2;
    int q1  = query(left(p),    L,  m, i, j);
    int q2  = query(right(p), m+ 1, R, i, j);
    
    return  min(q1,q2);
}


int main(int argc, char const *argv[]) {


    #ifndef ONLINE_JUDGE
        // For getting input from input.txt file
        freopen("in", "r", stdin);
        // Printing the Output to output.txt file
        freopen("out", "w", stdout);
        //Printing errors in out file
        freopen("out", "w", stderr);
    #endif

    int t,n,q,a,b;

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
            cin>>a>>b;

            cout<<query(1,1,n,a,b)<<'\n';
        }
    }
    return 0;
}
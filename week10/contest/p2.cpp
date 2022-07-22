/*
Complejidad algoritmica:
O(T (n + q lg n) )

T: es el numero de tests
n: es el numero de enteros de input
q: es el numero de queries que se hace en cada test

Por cada test O(T) se hace lo siguientes: 

- se crear un segment tree [build], cuya recursion es T(2 T(n/2)) por lo que su
    comlejidad es O(n)

- despues por cada query O(q) se hace lo siguiente dependiendo del caso:
    - caso 1: se llama  a la funcion query la cual es O(lg n) y la  funcion update O(lg n)
                esto se hace para obtener el valor de la posicion y luego updatearla a 0 en
                el segmen tree
    - caso 2: se llama  a la funcion  la  funcion update O(lg n), sumandole a la posicion i un valor x
    - caso 3: se llama  la funcionq uery para obtener el valor del rango O(lg n)
    

La idea del programa es correr un sum query, por lo que al contruir el arbol
obtenemos la suma de la derecha e izquierda. 

Esto mismo se tiene que mantener al momento del update. ya sea para
remalzar con 0 o sumar algun otro valor





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
const int N = 1e5+10;

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
    
    st[p] = st[left(p)] +  st[right(p)];
    
}


int query(int p, int L, int R, int i, int j){

    if(R <i || L > j) return 0;

    if(L >= i &&  R <= j) return st[p];

    int m = (L + R) / 2;
    int q1  = query(left(p),    L,  m, i, j);
    int q2  = query(right(p), m+ 1, R, i, j);
    
    return  q1 + q2;
}

void update(int p, int L, int R, int i, int x){

    if(L == R){
        if(x == 0) st[p] = x;
        else st[p] += x;
        return ;
    }

    int m = (L + R) / 2;
    

    if(i <= m){
        update(left(p), L, m, i,x);
    }
    else{
        update(right(p), m+ 1, R,i,x);
    } 
    st[p] =  st[left(p)] + st[right(p)];

}


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



            if(c == 1){
                cin>>a;
                
                cout<<query(1,1,n,a+1,a+1)<<'\n';
                update(1, 1, n, a+1, 0);
                

            }
            else if(c == 2){   
                cin>>a>>b;
                update(1, 1, n, a+1, b);
            }
            else{
                cin>>a>>b;
                cout<<query(1,1,n,a+1,b+1)<<'\n';
            }

        }
    }
    return 0;
}
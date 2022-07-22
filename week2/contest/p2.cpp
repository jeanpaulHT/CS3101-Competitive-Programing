// www.paginaPregunta.com

/*********************************DOCUMENTACIÓN*********************************

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor

Complejidad de tiempo = O(n! *  n): 
se recorre todas las permutaciones, y por cada permutacion se verifica que 
sean igual a alguno de los dos arreglos. Si los dos arreglos son iguales se entrega el resultado, caso contrario 
retorna 0

Complejidad de espacio = O(n) con 
Se una un 3 vectores de tamaño n. 2 para los arreglos del input y uno para permutar en
orden alfabetico

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

int N = 8;
int n;


vi t;

bool eq_p(vi & p){
    FOR(i, 0, n-1){
        if(t[i] != p[i]) return false; 
    }
    return true;
}

bool eq_q(vi &q){
    FOR(i, 0, n-1){
        if(t[i] != q[i]) return false; 
    }
    return true;
}


void sol(vi &p, vi &q){
    t = p;
    int dp = -1,dq = -1,counter = 0;

    sort(all(t));

    do{
        if(eq_p(p)) dp = counter;
        if(eq_q(q)) dq = counter;
        
        counter++;
    }while(next_permutation(all(t)));
    cout<<abs(dp - dq);
}

int main(int argc, char const *argv[]) {
    cin>>n;
    vi p(n);
    vi q(n);
    FOR(i, 1 , n){
        cin>>p[i-1];
    }

    FOR(i, 1 , n){
        cin>>q[i-1];
    }
    
    sol(p,q);

    return 0;
}
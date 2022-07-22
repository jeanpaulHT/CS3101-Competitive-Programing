// www.paginaPregunta.com

/*********************************DOCUMENTACIÓN*********************************

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor

Complejidad de tiempo = O(n^k): donde n es el numero de simbolos(en este caso es 10 porque usamos digitos) y k es los caracteres
que conforman el pin

En el peor de los casos, en donde no hay restriccion en donde en que simbolos obligatoriamente usarse o no usarse.
Estariamos explorando todas las combinaciones de formar un pin de k simbolos con nuestro n simbolos.
Asi que todos los simbolos posibles del pin:  k_1, k_2, k_3 ... k_k. tendiramos que explorar para todos los n en cada posicion.

Complejidad de espacio = O(n)  donde n es el numero de simbolos(en este caso es 10 porque usamos digitos)

El problema solo es contar el numero de posibilidades asi que no necesitamos espacio adicional mas que
un contenedor para los simbolos que se tienen que usar obligatoriamente

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

#define N 10



bool used[N];

int cnt_digits = 0;
int ans  = 0;
string str;


void generar(int pos, int must_dg){
    if(pos == 4){
        if(must_dg == cnt_digits) ans++;
        return ;
    }

    FOR(i,0,9){
            
        if(used[i] && str[i] != 'x'){
            used[i] = 0;
            generar(pos + 1, must_dg + 1);
            used[i] = 1;
        }
        else if(str[i] != 'x'){
            generar(pos+1, must_dg);
        }

    }

}


int main(int argc, char const *argv[]) {
    cin>>str;
    for(int i = 0; i < sz(str) ;i++){
        if(str[i] == 'o'){
            cnt_digits++;
            used[i] = 1;
        }
    }

    generar(0,0);
    cout<<ans;

    

    return 0;
}
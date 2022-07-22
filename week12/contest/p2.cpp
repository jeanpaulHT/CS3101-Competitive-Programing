/*

Complejidad algoritmica: O(tc * |v||v-1| )

tc: el numero de casos
v : el conjunto de vertices



hacemos una modificacion al dfs para tomar en cuenta un los padres de los nodos.

Al recorrer un dfs con un nodo u, si el nodo v no esta visitado; recorremos por v y definimos a
su padre como u. Ademas de mantener un registro del  nodo inicial (wi) y final del circuito (wf).

si al terminar el recorrido dfs inicial encontramos con que el nodo final no tiene como padre
al nodo final entonce spodemos decir que no hay un circuito.


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
const int N = 1024 + 10;

vector<vector<int>> adj;

bool vis[N];
int p[N];

int n,m;

void dfs(int u){

}

void sol(){


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
    

    return 0;
}
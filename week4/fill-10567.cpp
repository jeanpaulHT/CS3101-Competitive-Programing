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

#define INF (1<<30)

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




int t;
vector<vi> idx(257);
string str, q;


void sol(){
    
    bool sucess = true;
    int first = INF;
    int last = -1;

    FOR(i, 0, sz(q)-1 ){
        char c = q[i];

        auto it = upper_bound(idx[c].begin(), idx[c].end(), last);
        int new_pos = distance(idx[c].begin(), it);
        
        if(last >= idx[c][new_pos]){
            sucess = false;
            break;
        }
        last = idx[c][new_pos];
        first = min(first, last);


    }

    if(sucess){
        cout<<"Matched "<<first<<" "<<last<<endl;
    }
    else{
        cout<<"Not matched\n";
    }
}

int main(int argc, char const *argv[]) {
    
    cin>>str>>t;

    int j = 0;

    for(auto ch: str){
        idx[ch].PB(j++); 
    }


    FOR(i,0,t-1){
        cin>>q;
        sol();

    }

    return 0;
}
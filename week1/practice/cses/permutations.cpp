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

int n;
vi arr;


bool verify(){
    bool cond = true;
    FOR(i, 1, sz(arr) - 1){
        if(abs(arr[i] - arr[i-1] ) == 1) cond= false;
    }
    return cond;
}

void sol1(){
    int temp = (n%2 == 0) ? n : n-1;
    FOR(i,1,n/2){
        arr.push_back(temp);
        temp -= 2;
    }
    
    temp = (n%2 == 0) ? n-1: n;
    FOR(i, 1 , n - n/2){
        arr.push_back(temp);
        temp -=2;
    }
}

void sol2(){
    
    int temp = 2;
    FOR(i,1,n/2){
        arr.push_back(temp);
        temp += 2;
    }
    
    temp = 1;
    FOR(i, 1 , n - n/2){
        arr.push_back(temp);
        temp +=2;
    }

}

int main(int argc, char const *argv[]) {
    cin>>n;

    bool solved;
    
    sol1();
    solved = verify();
    if(!solved){
        arr.clear();
        sol2();
        solved = verify();
    }

    if(solved){
        for(auto it : arr){
            cout<<it<<' ';
        }
    }
    else
        cout<<"NO SOLUTION";

    return 0;
}
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


// out: 9
vi s = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0};


int binarySearch(vi arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x && arr[mid - 1] != x)
            return mid;

        if(arr[mid] == x)
            return binarySearch(arr, l, mid-1,x);
            
 

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 

        return binarySearch(arr, mid + 1, r, x);
    }
 
    return -1;
}

int main(int argc, char const *argv[]) {

    int res = binarySearch(s, 0, sz(s) - 1, 1);
    

    cout<<res;
    
    return 0;
}
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
const int N = 5e3+10;

const int max_int = ~(1<<31);


#define left(x) (x<<1)
#define right(x) (x<<1) + 1


int A[N];

int st[N];

void build(int p , int L, int R){
    
    if(L == R) st[p] = A[L];

    int m = (L + R) /2;

    build(left(p), L, m);
    build(right(p), m+1, R);
    
    st[p] = min( st[left(p)], st[right(p)]);
    
}


int insert(int p, int L, int R, int i, int j){
    
    if(R <  i || L >j) return INF;

    if(L>= i && R <= j){
        return st[p];
    }

    int m = (L+R)/2;
    int q1 = insert(left(p), L,m, i,j);
    int q2 = insert(right(p), m+1,R, i,j);

    return min(q1,q2);
}

void update(int p, int L, int R, int i, int x){

    if(L == R) { st[p] = x; return;}

    int m = (L + R) / 2;

    if(i <= m){
        update(left(p), L, m, i, x);
    }
    else{
        
        update(right(p), m+1 , R, i, x);
    }

    


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
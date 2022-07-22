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



#define left(x) (x << 1)
#define right(x) (x << 1) + 1

ll st[4*N];
ll A[N];



ll n,q;

void build(int p, int L, int R){
    if(L == R){
        st[p] = A[L]; 
        return;
    }

    int m = (L+R)/2;
    build( left(p), L,m);
    build( right(p), m+1,R);

    st[p] = max( st[left(p)] , st[right(p)]);
}


// ll query(ll cur_node, ll start, ll end, , ll left, ll right)

int query(int p, int L, int R,  int x){



    if(L == R) return (st[p] >= x) ? L: 0;
    

    int m = (L+R) / 2;

    if(st[left(p)] >= x){
        return query(left(p), L,m,x);
    }
    else if(st[right(p)] >= x){
        return query(right(p), m+1,R,x);
    }
    else return 0;
}


void update(int p, int L, int R, int i, int x){

    if(L == R) {st[p] =  st[p] - x; return;}

    
    int m = (L + R)/2;
    if(i <= m){
        update(left(p), L, m, i, x);
    }
    else{
        update( right(p), m + 1, R, i, x);
    }

    st[p] = max( st[left(p)], st[right(p)] );
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

    cin>>n>>q;

    memset(st, INF, N);
    FOR(i,1,n) cin>>A[i];
    build(1,1,n);



    // cout<<"A: ";
    // FOR(i,1,n) cout<<A[i]<<" ";
    // cout<<'\n';

    // cout<<"st: ";
    // FOR(i,1,2*n-1) cout<<st[i]<<" ";
    // cout<<'\n';
    

    int x,a,b;

    while(q--){
        cin>>x;

        
        // printf("res for [%d,%d]: ",a,b);
        int i =   query(1, 1, n, x);
        cout<<i<<'\n';


        if(i !=0) update(1,1,n,i,x);
        

        // printf("st(%d):", x);
        // FOR(i,1,2*n-1) cout<<st[i]<<" ";
        // cout<<'\n';
    

    }
    

    
    return 0;
}
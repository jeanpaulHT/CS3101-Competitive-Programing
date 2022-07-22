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



//st.F : ans
//st.F.F: freq of element to the left
//st.F.S: freq of eleent to the right
pair<ll, pll> st[4*N];

ll A[N];


ll n,q;

void build(int p, int L, int R){

    if(L == R){
        st[p].F = st[p].S.F = st[p].S.S = 1;
        return;
    }


    int m = (L+R)/2;
    build( left(p), L,m);
    build( right(p), m+1,R);


    st[p].F = max({
        st[left(p)].F,
        st[right(p)].F
    });

    if(A[m] == A[m+1]){
        st[p].F = max( st[p].F , st[left(p)].S.S + st[right(p)].S.F);
    }

    st[p].S.F = st[left(p)].S.F;
    st[p].S.S = st[right(p)].S.S;

    if(A[m] == A[R]){
        st[p].S.S = st[left(p)].S.S + st[right(p)].S.S;
    }
    if(A[L] == A[m+1]){
        st[p].S.F = st[left(p)].S.F + st[right(p)].S.F;
    }

}


pair<ll, pll> query(int p, int L, int R, int i, int j){



    if(R < i || L > j) return {0, {0,0}};

    if( L >= i &&  R <= j)
        return st[p];
    

    int m =  (L+R)/2;
    pair<ll, pll> q1 = query(left(p),  L, m, i, j);
    pair<ll, pll> q2 = query(right(p), m+1, R, i, j);
    
    pair<ll, pll> q3  = {0, {q1.S.F, q2.S.S} }; 
    
    if(A[m]== A[m+1]){
        q3.F =  (q1.S.S + q2.S.F);
        if(A[m] == A[R]){
            q3.S.S = q1.S.S + q2.S.S;
        }
        if(A[L] == A[m+1]){
            q3.S.F = q1.S.F + q2.S.F;
        }
    }
    
    return max({
        q1,q2, q3,
    }, [](const pair<ll, pll>  s1, const pair<ll, pll>  s2){
        return s1.F < s2.F;
    }
    );
}

int main(int argc, char const *argv[]) {


    #ifndef ONLINE_JUDGE
        // For getting input from input.txt file
        freopen("in", "r", stdin);
        // Printing the Output to output.txt file
        freopen("out", "w", stdout);
    #endif

    while(cin>>n){

        if(n == 0) break;
        cin>>q;

        FOR(i,1,n) cin>>A[i];
        build(1,1,n);



        // cout<<"A: ";
        // FOR(i,1,n) cout<<A[i]<<" ";
        // cout<<'\n';

        // cout<<"st: ";
        // FOR(i,1,2*n-1) printf("(%lld)[%lld,%lld]", st[i].F, st[i].S.F, st[i].S.S);
        // cout<<'\n';
        


        int a,b;

        while(q--){
            cin>>a>>b;
            // printf("res for [%d,%d]: ",a,b);
            cout<< query(1, 1, n, a, b).F<<"\n";
        }
    }

    
    return 0;
}
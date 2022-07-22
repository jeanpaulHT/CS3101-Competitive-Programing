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



#define left(x) x << 1
#define right(x) (x << 1) + 1

ll st[4*N];
ll A[N];



ll n,q;

int res_pro(int q1, int q2){
    if(q1 == 2 || q2 == 2) return 2;
    else if(q1 == -1 && q2 == -1) return 1;
    else return min(q1, q2);
}

void build(int p, int L, int R){
    if(L == R){
        st[p] = (A[L]  == 0) ? 2 : (
            (A[L] < 0) ? -1 : 1
        );

        return;
    }

    int m = (L+R)/2;
    build( left(p), L,m);
    build( right(p), m+1,R);




    st[p] = res_pro(st[left(p)], st[right(p)]);
}



int query(int p, int L, int R, int i, int j){



    if(R < i || L > j) return INF;

    if( L >= i &&  R <= j)
        return st[p];
    

    int m =  (L+R)/2;
    int q1 = query(left(p),  L, m, i, j);
    int q2 = query(right(p), m+1, R, i, j);
    

    return res_pro(q1, q2);
}


void update(int p, int L, int R, int i, int x){

    if(L == R) {
        st[p] = (x  == 0) ? 2 : (
            (x< 0) ? -1 : 1
        );

        return;
    }

    
    int m = (L + R)/2;
    if(i <= m){
        update(left(p), L, m, i, x);
    }
    else{
        update( right(p), m + 1, R, i, x);
    }

    
    st[p] = res_pro(st[left(p)], st[right(p)]);
}


int main(int argc, char const *argv[]) {


    #ifndef ONLINE_JUDGE
        // For getting input from input.txt file
        freopen("in", "r", stdin);
        // Printing the Output to output.txt file
        freopen("out", "w", stdout);
    #endif

    while(cin>>n){
        
        cin>>q;

        memset(st, INF, N);
        FOR(i,1,n) cin>>A[i];
        build(1,1,n);



        // cout<<"A: ";
        // FOR(i,1,n) cout<<A[i]<<" ";
        // cout<<'\n';

        // cout<<"st: ";
        // FOR(i,1,2*n-1) cout<<st[i]<<" ";
        // cout<<'\n';
        

        char k;
        int a,b;

        while(q--){
            cin>>k>>a>>b;
            if(k == 'C'){
                update(1,1,n,a,b); 

            }
            else{
                int prod = query(1,1,n, a,b);

                if(prod == 2) cout<<"0";
                else if(prod == 1) cout<<"+";
                else cout<<"-";
            }
        }
        cout<<'\n';
    }

    
    return 0;
}
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
const int N = 2e2+100;
 
const int W = 50;
const int H = 200;

int a[H+10][W * 4 + 10];
 
int w,h;

 
// set<pair<int,int>> res;


bool fuera(int i,int j){
    return (i<0 or j < 0 or i >= h or j>= w * 4);
}

void floodfill(int i,int j, int colFrom, int colTo){
    
    if(fuera(i,j) or a[i][j] != colFrom) return ;
    
    a[i][j] = colTo;
    
    floodfill(i-1,j,colFrom,colTo);
    floodfill(i,j-1,colFrom,colTo);
    floodfill(i,j+1,colFrom,colTo);
    floodfill(i+1,j,colFrom,colTo);
}
 

void solve(){


    // cnt[0][0]++;
    floodfill(0,0,0,2);
    
    //search iterative until you find a black pixel
    //count(i,j)



    // printf("Case %d: %d %d\n",t,even,odd);
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
 
 
    int tc;
    cin>>tc;

    for(t = 1; t <= tc;t++){


        memset(a, 0, N*N);
        memset(vis, 0, N*N);
        memset(cnt, 0, N*N);
        // res.clear();
        
        cin>>r>>c>>m>>n;
        int w,x,y;


        // if(t == 14){
        //     printf("%d %d %d %d\n",r,c,m,n);
        // }
        cin>>w;
        FOR(i,1,w){
            cin>>x>>y;
            a[x][y] = 1;

            // if(t == 14) cout<<x<<" "<<y<<'\n';
        }

        solve();        

    }
 
    return 0;
}
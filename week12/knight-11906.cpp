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
 

bool vis[N][N];
int a[N][N];
int cnt[N][N];
 
int n,m,r,c,t;

const int Kn = 3;
const int di[4] = {1,1,-1,-1}, dj[4] = {1,-1,1,-1};
 
// set<pair<int,int>> res;


bool fuera(int i,int j){
    return (i<0 or j < 0 or i >= r or j>=c);
}


void contar(int i, int j){
    FOR(k,0,Kn){
        int ni = i + di[k] * m;
        int nj = j + dj[k] * n;
        if(fuera(ni,nj) or  a[ni][nj] ) continue;

        cnt[ni][nj]++;
    }

    FOR(k,0,Kn){
        int ni = i + di[k] * n;
        int nj = j + dj[k] * m;
        if(fuera(ni,nj) or  a[ni][nj] ) continue;

        cnt[ni][nj]++;
    }
}


void dfs(int i, int j){
 
    vis[i][j] = 1;

    FOR(k,0,Kn){
        int ni = i + di[k] * n;
        int nj = j + dj[k] * m;

        cnt[ni][nj]++;
        
        if(fuera(ni,nj) or  a[ni][nj] or  vis[ni][nj] ) continue;
        
        // res.insert({ni,nj});
        dfs(ni,nj);
    }

    FOR(k,0,Kn){
        int ni = i + di[k] * m;
        int nj = j + dj[k] * n;

        cnt[ni][nj]++;

        if(fuera(ni,nj) or  a[ni][nj] or  vis[ni][nj] ) continue;

        // res.insert({ni,nj});
        dfs(ni,nj);
    }
}
 

void solve(){


    // cnt[0][0]++;
    dfs(0,0);

    int odd = 0,even = 0;

    FOR(i, 0,  r-1){
        FOR(j,0,c-1){

            if(vis[i][j]){        
                //counted twice
                if(n==m or n == 0 or m == 0) {
                    cnt[i][j] /= 2;
                }

                if(cnt[i][j]%2) odd++;
                else even++;
            }
        }
    }



    printf("Case %d: %d %d\n",t,even,odd);
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
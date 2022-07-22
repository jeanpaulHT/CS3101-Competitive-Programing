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
 
const int X = 2e3+10;
const int Y = 2e3+10;

int a[X][Y];
int n,m;

 
// set<pair<int,int>> res;


bool fuera(int i,int j){
    return (i<0 or j < 0 or i >= n or j>= m);
}



void floodfill(int i,int j, int colFrom, int colTo){
    
    if(fuera(i,j) or a[i][j] != colFrom) return ;
    
    a[i][j] = colTo;
    
    floodfill(i-1,j,colFrom,colTo);
    floodfill(i,j-1,colFrom,colTo);
    floodfill(i,j+1,colFrom,colTo);
    floodfill(i+1,j,colFrom,colTo);
}
 


void print(){
    FOR(i,0,n-1){
        FOR(j,0,m-1){
            cout<< (char) a[i][j];
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void solve(){

    int room = 0;
    FOR(i,0,n-1){
        FOR(j,0,m-1){
            if(a[i][j] == '.'){
                floodfill(i,j,'.','#');
                room++;
                // print();

            }
            
        }
    }

    cout<<room<<'\n';
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
 
 
    cin>>n>>m;


    char c;
    FOR(i,0,n-1){
        FOR(j,0,m-1){
            cin>>c;
            a[i][j] = c;
        }
    }
    solve();
 
    return 0;
}
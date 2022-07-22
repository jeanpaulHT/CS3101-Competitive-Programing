#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair


using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main(){
    int t,m,n;

    while(cin>>t){
        if(t == 0) break;
        cin>>n>>m;
        while(t--){
        int x,y;
        cin>>x>>y;
        
        int sidex = x-n;
        int sidey = y-m ;

        if(sidex == 0 || sidey == 0) cout<<"divisa";
        else{
            
            if(sidey >0) cout<<"N";
            else cout<<"S";

            if(sidex>0) cout<<"E";
            else cout<<"O";

        }
        cout<<"\n";
        }
    }

    return 0; 
}
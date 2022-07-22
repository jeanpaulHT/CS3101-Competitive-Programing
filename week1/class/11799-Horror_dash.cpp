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
    int t;
    cin>>t;

    for(int i = 0; i < t; i++){
        int n, val, ans = -1; 
        cin>>n;
        for(int j = 0; j < n; j++){
            cin>>val;
            ans = max(val,ans);
            
        }
        cout<<"Case "<<i+1<<": "<<ans<<'\n';
    }    
    return 0;
}
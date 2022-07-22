#include <bits/stdc++.h>

#define all(A) begin(A), end(A)

#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair


using namespace std;

typedef long long ll;
typedef pair <int, int> pii;


int arr[1000];

#define max_limit INT_MAX

int main(){
    int n,b,h,w;

    while(cin>>n>>b>>h>>w){

        int res =  max_limit;

        for(int i = 0; i < h ;i++){
            int p, temp = 0;
            cin>>p;
            cout<<p<<'\n';
            
            for(int a = 0; a < w;a++){
                cin>>arr[a];
                cout<<arr[a]<<' ';
            }
            cout<<'\n';

            for(int a = 0; a < w;a++){
                if(arr[a] < n){temp=  max_limit; break;}
                temp = temp  + (n*p) ;
            }
            res = min(res,temp);
        
        }
        cout<<res<<" "<<b<<"\n";
        if(res > b) cout<<"stay home\n";
        else cout<<res<<'\n';    
    }        
    return 0;
}
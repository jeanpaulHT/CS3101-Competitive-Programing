#include <bits/stdc++.h>

#define all(A) begin(A), end(A)

#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair


using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int arr[256] = {INT_MAX};
// string vec[3][3];
vector<vector<string>> vec(3, vector<string> (3));

#define unused INT_MAX
#define heavy 1
#define light -1

pii get_w(string w){
    int wl,wr;

    if(w == "even")  wl = wr = 0;
    else if(w == "up") {wl = heavy; wr = light;}
    else if(w == "down") {wl = light; wr = heavy;}

    return mp(wl,wr);
}

void solve(){
    
    for(int i = 0; i < 3; i++){
        string l,r,w;
        int wl, wr;

        l = vec[i][0];
        r = vec[i][1];
        w = vec[i][2];
            
        auto p = get_w(w);
        wl = p.first;
        wr = p.second;
            
        if(wl != 0 && wr != 0){
            for(auto &c1: l) {
                if(arr[c1] == 0) continue;
                else if(arr[c1] == unused ) arr[c1] = wl;
                else arr[c1] += wl;
            }
            for(auto &c2: r)  {
                if(arr[c2] == 0) continue;
                else if(arr[c2] == unused ) arr[c2] = wr;
                else arr[c2] += wr;
            }
        }
        else{
            for(auto &c1: l) {arr[c1] = 0;}
            for(auto &c2: r)  {arr[c2] = 0;}
        }
    }

              

    int max_abs = 0;
    char id;
    for(int i = 'A'; i <='L'; i++){
        if(arr[i] == unused) continue;
        if(max_abs < abs(arr[i]) ){max_abs = abs(arr[i]); id = i;}
    }

    cout<<id<<" is the counterfeit coin and it is ";
    if(arr[id] > 0) cout<<"heavy.\n";
    else cout<<"light.\n";
    

}

int main(){

    int n;
    cin >>n;

    for(int t = 0; t < n; t++){
        
        for(int i = 'A'; i <='L'; i++){
            arr[i] = unused;
        }


        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cin>>vec[i][j];
            }
        }
        solve();
    }

    return 0;
}
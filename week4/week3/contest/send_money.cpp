// www.paginaPregunta.com

/*********************************DOCUMENTACIÓN*********************************

Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor

Complejidad de tiempo = O(*) con *=?
Complejidad de espacio = O(*) con *=?

*******************************************************************************/

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


vector<string> s(3);
vector<int> ans(3,0);

vector<map<char, int>> digit(3);


// bool cond3(int n1, int n2, int pos_s1, int pos_s2){
//     string s1 = to_string(n1);
//     string s2 = to_string(n2);
    
//     for(int i = 0; i < min( sz(s1),  sz(s2) );i++){

//         if(s1[i] == s2[i] || s[pos_s1][i] == s[pos_s2][i] ){
//             if(s1[i] == s2[i] && s[pos_s1][i] == s[pos_s2][i]) continue;
//         }
//     }
//     return true;
// }


// bool generar(int pos){

//     if(pos == 2){
        
//         ans[2]= ans[0] + ans[1];
        
//         if(cond3(ans[0], ans[2], 0,2) == true && 
//             cond3(ans[1],ans[2], 1,2) == true) {
//                 return true;
//         }
        

//         return false;
//     }

//     FOR(i, 1, 9* sz(s[pos]) ){

//         ans[pos] = i;
        
//         if(pos == 1){
//             if(cond3(ans[0],  ans[1], 0,1) == false) continue;
//         }
        
//         if(generar(pos+1) == true) return true;
//     }

//     return false;
// }


bool cond3(int pos_s1, int pos_s2){

    
    for(auto it: digit[pos_s1]){
        if(digit[pos_s2].find(it.first) != digit[pos_s2].end()){
            if(digit[pos_s2][it.first] != digit[pos_s1][it.first] ) return false;
        }
    }
    return true;
}


bool generar(int pos){

    if(pos == 2){
        
        ans[2]= ans[0] + ans[1];
        
        int temp = ans[pos];
        string str_temp = to_string(temp);
        
        for(int i = 0; i < sz(s[pos]);i++){
            digit[pos][s[pos][i]] = ( (int) str_temp[i] - '0' );
        }
        
        if(cond3(0,2) == true && 
            cond3( 1,2) == true) {
                return true;
        }
        

        return false;
    }

    while(ans[pos] <= 9* sz(s[pos])){
        int temp = ans[pos];
        string str_temp = to_string(temp);

        for(int i = 0; i < sz(s[pos]);i++){
            digit[pos][s[pos][i]] = ( (int) str_temp[i] - '0' );
        }
        
        if(pos == 1){
            if(cond3(0,1) == false){
                ans[pos]++;
                continue;
            }
        }


        if( generar(pos+1) ) return true;
        ans[pos]++;
    }
    
    return false;
}




void preproces(){
    ans[0] = pow(10,sz(s[0]) - 1);
    ans[1] = pow(10,sz(s[1]) - 1);
    ans[2] = pow(10,sz(s[2]) - 1);
}


int main(int argc, char const *argv[]) {

    cin>>s[0]>>s[1]>>s[2];

    preproces();

    bool sucess = generar(0);

    if(sucess){
        for(auto it: ans) cout<<it<<" ";
    }
    else{
        cout<<"UNSOLVABLE";
    }
    

    return 0;
}
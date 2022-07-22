#include <bits/stdc++.h>

#define all(A) begin(A), end(A)

#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair


using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

string get_anal(string str){
    string trans = {};
    for(auto c: str){
        trans += tolower(c);
    }
    sort(all(trans));
    return trans;
}


int main(){
    string str;
    vector<string> arr;
    unordered_map<string, int> mp;

    while(cin>>str){
        if(str == "#") break;
        arr.push_back(str);
        
        mp[get_anal(str)]++;
    }

    sort(all(arr));

    //tengo 3 años
    for(auto &trans: arr){

       if(mp[get_anal(trans)] >1) continue;
       
       cout<<trans<<'\n';
    }

    return 0;
}
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

    for(int i = 1; i<=t ; i++){
        vector<int> vec(3);
        cin>>vec[0]>>vec[1]>>vec[2];
        sort(all(vec));

        cout<<"Case "<<i<<": "<<vec[1]<<'\n';
    }

    return 0; 
}
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
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        sort(all(str));

        do
        {
            cout<<str<<'\n';
        } while (next_permutation(all(str)));
    }

}
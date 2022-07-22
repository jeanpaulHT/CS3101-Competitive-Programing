#include <bits/stdc++.h>

#define all(A) begin(A), end(A)

#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair


using namespace std;

typedef long long ll;
typedef pair <int, int> pii;


bool inline is_perfect_square(int n){
    int a = sqrt(n);
    return a * a == n;
}

bool is_palindrome(string str){
    for(int i = 0; i < sz(str)/2 ; i++){
        if(str[i] != str[sz(str) - i - 1]) return false;
    }
    return true;
}

int main(){
    int t, l;

    cin>>t;

    cin.ignore(INT_MAX, '\n');

    for(int ca =  1 ; ca<= t; ca++){
        string str, word;
        bool flag = true;

        getline(cin,str);



        for(char c: str){
            if(isalpha(c)) word.push_back(c);
        }

        int n = sqrt(sz(word));
        //checks perfect square and condition 3, 4
        if(!is_perfect_square(sz(word)) || !is_palindrome(word)) flag = false;
        else{
        
            string rev = {};
            for(int j = 0; j< n; j++){
                for(int i = 0; i < n;i++){
                    rev+= word[ i * n+j];
                }
            }
            if(!is_palindrome(rev)) flag = false;
        }

        cout<<"Case #"<<ca<<":\n";
        if(flag)cout<<n<<'\n';
        else cout<<"No magic :(\n";

    }

    return 0;
}
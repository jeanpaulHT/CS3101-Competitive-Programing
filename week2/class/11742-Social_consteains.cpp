#define F first
#define S second
#define PB push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;

/*
general idea is:
going through all possible permutations of the teens
and adding up all the ones that match the constraints
*/

int n, m, a, b, c; // variables mentioned in the description
/*
- n: size of the group
- m: number of constraints
- a: teenager labeled as a
- b: teenager labeled as b
- c: seats apart they have to be (at max if >0, at least if <0)
*/
vector<pair<pii,int>> x; // constraints
/* has the format: 
<<teen labeled as i, teen labeled as j>, restriction k>
recall that if k > 0, it's at max k seats apart
and if k < 0, it's at least -k seats apart
*/
vi p; //permutations
/* index is teen # index, value is their position,
so if we have [3, 2, 4, 0, 1], then that means
teen 0 goes at position 3, teen 1 goes at position 2
and so on.
*/

bool check() {
    for (auto r : x) {
        int i = r.F.F;
        int j = r.F.S;
        int k = r.S;
        if(k>0 && abs(p[i]-p[j]) > k) return false;
        if(k<0 && abs(p[i]-p[j]) < -k) return false;
    }
    return true;
}

void solve() {
    int cont = 0;
    FOR(i,0,n-1) p.PB(i);
    do {
        if(check()) cont++;
    } while (next_permutation(p.begin(), p.end()));
    cout<<cont<<endl;
}

int main() {
    while(true) {
        cin>>n>>m;
        if(n==0) break;
        FOR(i,1,m) {
            cin>>a>>b>>c;
            x.PB({{a,b},c});
        }
        solve();
        x.clear();
        p.clear();
    }
  return 0;
}
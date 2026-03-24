#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long; using u64 = uint64_t;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;

int solve(char c){
    int ret = 0, l = 0, r = n - 1;
    int nl = l, nr = r;
    while(1){
        while(s[nl] == c && nl <= r) nl++;
        while(s[nr] == c && nr >= l) nr--;
        if(nl > r || nr < l) break;

        if(nl - l <= r - nr){
            ret += 2 * (nl - l);
            nl++; l = nl;
        }
        else{
            ret += 2 * (r - nr);
            nr--; r = nr;
        }
        ret++;
    }

    return ret;
}

void run(){
    cin >> n >> s;
    cout << min(solve('0'), solve('1')) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

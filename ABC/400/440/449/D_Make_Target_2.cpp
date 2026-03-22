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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;

ll result;
void run(){
    int l, r, d, u; cin >> l >> r >> d >> u;
    if(l <= 0 && r >= 0 && d <= 0 && u >= 0) result++;
    for(int i = 1;2 * i < MAX;i++){
        if(l <= 2 * i && r >= 2 * i){
            result += max(min(2 * i, u) - max(-2 * i, d) + 1, 0);
        }

        if(l <= -2 * i && r >= -2 * i){
            result += max(min(2 * i, u) - max(-2 * i, d) + 1, 0);
        }

        if(d <= 2 * i && u >= 2 * i){
            result += max(min(2 * i - 1, r) - max(-2 * i + 1, l) + 1, 0);
        }

        if(d <= -2 * i && u >= -2 * i){
            result += max(min(2 * i - 1, r) - max(-2 * i + 1, l) + 1, 0);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

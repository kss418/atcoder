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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll pa[MAX], pb[MAX], result;

class _bs { // integer
public:
    template <class F>
    static ll max_right(ll l, ll r, const F& f) {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) >> 1ll;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }

    template <class F>
    static ll min_left(ll l, ll r, const F& f) {
        ll lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) >> 1ll;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};

void run(){
    cin >> n >> m >> k >> s;
    for(int i = 1;i <= n;i++){
        pa[i] = pa[i - 1] + (s[i - 1] == 'a');
        pb[i] = pb[i - 1] + (s[i - 1] == 'b');
    }

    pb[n + 1] = INF;
    for(int i = 1;i <= n;i++){
        auto fa = [&](int idx){
            return (pa[idx] - pa[i - 1]) >= m;
        };

        auto fb = [&](int idx){
            return (pb[idx] - pb[i - 1]) < k;
        };

        ll l = _bs::min_left(i, n + 1, fa);
        ll r = _bs::max_right(i, n + 1, fb);

        if(l == n + 1 || r == n + 1) continue;
        result += max(r - l + 1, 0ll);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

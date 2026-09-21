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
ll a[MAX], b[MAX], pre[MAX];

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
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i];
    
    sort(a + 1, a + n + 1);
    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + a[i];
        pre[i] %= MOD;
    }

    ll result = 0;
    for(int i = 1;i <= m;i++){
        auto f = [&](ll cur){
            return a[cur] <= b[i];
        };

        auto idx = _bs::max_right(0, n, f);
        result += b[i] * idx;
        result %= MOD;

        result -= pre[idx];
        result %= MOD;

        result += pre[n] - pre[idx];
        result %= MOD;

        result -= b[i] * (n - idx);
        result %= MOD;
    }

    cout << (result + MOD) % MOD;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

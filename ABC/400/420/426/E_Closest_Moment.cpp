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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;

class _fts { // real
public:
    template <class F>
    static ld max(ld l, ld r, const F& f, int iter = 120) {
        for(int i = 0; i < iter; i++){
            ld st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            if(f(st) < f(en)) l = st;
            else r = en;
        }
        return std::max(f(l), f(r));
    }

    template <class F>
    static ld min(ld l, ld r, const F& f, int iter = 120) {
        for(int i = 0; i < iter; i++){
            ld st = (2 * l + r) / 3, en = (l + 2 * r) / 3;
            if(f(st) > f(en)) l = st;
            else r = en;
        }
        return std::min(f(l), f(r));
    }
};

int x[4], y[4];
ld dist(int i){
    int dx = x[i] - x[i + 1], dy = y[i] - y[i + 1];
    return sqrtl(dx * dx + dy * dy);
}

ld f1(ld t){
    ld r1 = t / dist(0);
    ld r2 = t / dist(2);
    ld x1 = x[0] + (x[1] - x[0]) * r1, y1 = y[0] + (y[1] - y[0]) * r1;
    ld x2 = x[2] + (x[3] - x[2]) * r2, y2 = y[2] + (y[3] - y[2]) * r2;
    ld dx = x1 - x2, dy = y1 - y2;
    return sqrtl(dx * dx + dy * dy);
}

ld f2(ld t){
    ld r1 = min<ld>(t / dist(0), 1);
    ld r2 = min<ld>(t / dist(2), 1);
    ld x1 = x[0] + (x[1] - x[0]) * r1, y1 = y[0] + (y[1] - y[0]) * r1;
    ld x2 = x[2] + (x[3] - x[2]) * r2, y2 = y[2] + (y[3] - y[2]) * r2;
    ld dx = x1 - x2, dy = y1 - y2;
    return sqrtl(dx * dx + dy * dy);
}

void run(){
    for(int i = 0;i < 4;i++) cin >> x[i] >> y[i];
    ld mn = min(dist(0), dist(2)), mx = max(dist(0), dist(2));
    cout.precision(20);
    cout << min(_fts::min(0, mn, f1), _fts::min(mn, mx, f2)) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

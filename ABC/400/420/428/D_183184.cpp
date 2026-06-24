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

ll pow10(int cnt){
    ll ret = 1;
    for(int i = 1;i <= cnt;i++) ret *= 10;
    return ret;
}

void run(){
    cin >> n >> m;
    ll result = 0;
    for(int i = 1;i <= 10;i++){
        ll l = max(pow10(i - 1), n + 1);
        ll r = min(pow10(i) - 1, n + m);

        l += n * pow10(i); r += n * pow10(i);
        result += max((ll)(floor(sqrtl(r)) - ceil(sqrtl(l)) + 1), 0ll);
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();

    return 0;
}

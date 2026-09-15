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
int result;
map <ll, ll> mp;

void op(ll l, ll r){
    result -= r - l + 1;
    while(1){
        auto lb = mp.lower_bound(l);
        if(lb->x > r) break;
        result += min(r, lb->y) - max(l, lb->x) + 1;
        r = max(lb->y, r); l = min(lb->x, l);
        mp.erase(lb);
    }

    while(1){
        auto lb = --mp.lower_bound(l);
        if(lb->y < l) break;
        result += min(r, lb->y) - max(l, lb->x) + 1;
        l = min(lb->x, l); r = max(lb->y, r);
        mp.erase(lb);
    }

    mp.insert({l, r});
}

void run(){
    cin >> n >> m; result = n;
    mp.insert({INF, INF});
    mp.insert({MINF, MINF});

    while(m--){
        ll l, r; cin >> l >> r;
        op(l, r);
        cout << result << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

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
constexpr ll MAX = 23; // SET MAX SIZE
constexpr ll MOD = 998244353;

ll dp[1ll << MAX];
ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret = 1;

    char la = -1;
    for(int i = 0;i < n;i++){
        if(la == s[i] || !(cur & (1ll << i))) continue;
        ret += solve(cur ^ (1ll << i));
        if(ret >= MOD) ret -= MOD;
        la = s[i]; 
    }

    return ret;
}

void run(){
    cin >> n >> s; memset(dp, -1, sizeof(dp));
    cout << solve((1ll << n) - 1);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

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
ll a[MAX], d[MAX], result;
map <ll, ll> mp;

void push(ll idx, ll v){
    if(idx == INF) return;
    if(d[idx] != INF) result -= d[idx];
    d[idx] = min(d[idx], v);
    result += d[idx];
}

void run(){
    cin >> n; mp[0] = 0; mp[INF] = INF;
    memset(d, 0x3f, sizeof(d));
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++){
        ll now = a[i];
        ll pre = (--mp.lower_bound(a[i]))->y;
        ll nxt = mp.upper_bound(a[i])->y;
        
        ll pd = abs(a[i] - a[pre]), nd = abs(a[i] - (nxt != INF ? a[nxt] : INF));
        push(pre, pd); push(nxt, nd);

        d[i] = min({d[i], pd, nd}); result += d[i];
        mp[a[i]] = i;
        
        cout << result << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

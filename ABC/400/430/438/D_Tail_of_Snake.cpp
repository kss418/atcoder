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
ll a[MAX], b[MAX], c[MAX], pre[MAX], suf[MAX];
ll sum[MAX], sm = MINF, pm = MINF, all, result;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i], all += b[i];
    for(int i = 1;i <= n;i++) cin >> c[i];

    for(int i = 1;i <= n;i++){
        pre[i] = pre[i - 1] + a[i] - b[i];
        if(i != 1) sm = max(sm, pre[i - 1]);
        sum[i] += sm;
    }

    for(int i = n;i >= 1;i--){
        suf[i] = suf[i + 1] + c[i] - b[i];
        if(i != n) pm = max(pm, suf[i + 1]);
        sum[i] += pm;
    }

    for(int i = 2;i < n;i++) result = max(result, sum[i] + all);
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

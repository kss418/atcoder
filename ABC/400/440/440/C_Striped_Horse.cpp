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
ll a[MAX], sum[2 * MAX];

void run(){
    cin >> n >> m;
    for(int i = 0;i < 2 * m;i++) sum[i] = 0;

    ll all = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i]; all += a[i];
        sum[(i - 1) % (2 * m)] += a[i];
    }
    
    ll now = 0;
    for(int i = 0;i < m;i++) now += sum[i];

    ll result = all - now;
    for(int i = m;i < 4 * m;i++){
        now -= sum[(i - m) % (2 * m)];
        now += sum[i % (2 * m)];
        result = min(result, all - now);
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

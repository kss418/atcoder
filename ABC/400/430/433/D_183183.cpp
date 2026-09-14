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
map <ll, ll> mp[11];
ll result, a[MAX];

ll cal(ll x){
    ll ret = 0;
    while(x){
        x /= 10; ret++;
    }

    return ret;
}

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++){
        ll mul = 1;
        for(int j = 1;j <= 10;j++){
            mul *= 10; mul %= m;
            ll now = a[i] * mul;
            mp[j][now % m]++;
        }
    }

    for(int i = 1;i <= n;i++){
        ll mod = a[i] % m;
        mod = (mod ? m - mod : 0);
        result += mp[cal(a[i])][mod];
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

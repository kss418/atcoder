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
ll a[MAX];
priority_queue <pll, vector<pll>, greater<pll>> pq;

void run(){
    cin >> n; 
    for(int i = 1;i <= n;i++) cin >> a[i], pq.push({a[i], i});
    a[0] = a[n + 1] = MINF;
    
    ll result = 0;
    while(!pq.empty()){
        auto [cur, idx] = pq.top(); pq.pop();
        if(a[idx] != cur) continue;

        if(a[idx + 1] > cur + 1){
            result += a[idx + 1] - cur - 1;
            a[idx + 1] = cur + 1;
            pq.push({a[idx + 1], idx + 1});
        }

        if(a[idx - 1] > cur + 1){
            result += a[idx - 1] - cur - 1;
            a[idx - 1] = cur + 1;
            pq.push({a[idx - 1], idx - 1});
        }
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

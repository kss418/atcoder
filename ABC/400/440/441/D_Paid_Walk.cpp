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
vector <pll> adj[MAX];
vector <int> result;
ll st, en, l;

void dfs(ll cur, ll c = 0, ll len = 0){
    if(len == l){
        if(c >= st && c <= en) result.push_back(cur);
        return;
    }

    for(auto& [nxt, co] : adj[cur]) dfs(nxt, co + c, len + 1);
}

void run(){
    cin >> n >> m >> l >> st >> en;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
    }

    dfs(1);
    sort(all(result));
    result.erase(unique(all(result)), result.end());
    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

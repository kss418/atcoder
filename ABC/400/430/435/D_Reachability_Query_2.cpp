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
vector <int> adj[MAX];
bool use[MAX];

void dfs(int cur){
    if(use[cur]) return; use[cur] = 1;
    for(auto& nxt : adj[cur]) dfs(nxt);
}

void run(){
    cin >> n >> m;
    while(m--){
        int s, e; cin >> s >> e;
        adj[e].push_back(s);
    }

    cin >> k;
    while(k--){
        int op, v; cin >> op >> v;
        if(op == 1) dfs(v);
        else cout << (use[v] ? "Yes" : "No") << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

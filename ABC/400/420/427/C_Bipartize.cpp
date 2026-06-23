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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;

bool adj[MAX][MAX];
ll result = INF;

ll cal(int mask){
    ll ret = 0;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            bool ib = mask & (1 << i), jb = mask & (1 << j);
            if(ib != jb || !adj[i][j]) continue;
            ret++;
        }
    }

    return ret;
}

void run(){
    cin >> n >> m; 
    while(m--){
        int s, e; cin >> s >> e;
        s--; e--;
        adj[s][e] = adj[e][s] = 1;
    }  

    for(int i = 0;i < (1ll << n);i++) result = min(result, cal(i));
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
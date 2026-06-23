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

vector <int> adj[MAX];
char dp[MAX][11][2];

char solve(int cur, int cnt, bool turn){
    char& ret = dp[cur][cnt][turn];
    if(ret != -1) return ret; ret = turn ^ 1;
    if(!cnt) return ret = (s[cur - 1] == 'B');

    if(!turn){
        for(auto& nxt : adj[cur]){
            ret = min(ret, solve(nxt, cnt, turn ^ 1));
        }
    }
    else{
        for(auto& nxt : adj[cur]){
            ret = max(ret, solve(nxt, cnt - 1, turn ^ 1));
        }
    }

    return ret;
}

void run(){
    cin >> n >> m >> k >> s; 
    for(int i = 1;i <= n;i++) adj[i].clear();
    while(m--){
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
    }

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= k;j++) dp[i][j][0] = dp[i][j][1] = -1;
    }

    cout << (solve(1, k, 0) ? "Bob" : "Alice") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}
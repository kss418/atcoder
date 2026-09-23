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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll dp[MAX][50101], cnt[MAX];
bool v[MAX][50101];

void dfs(ll cur, ll sum){
    if(v[cur][sum]) return;
    if(!cur) return; v[cur][sum] = 1;

    if(sum && dp[cur][sum] == dp[cur][sum - 1]) dfs(cur, sum - 1);
    if(dp[cur][sum] == dp[cur - 1][sum]){
        dfs(cur - 1, sum);
        cnt[cur] |= 1;
    }

    if(sum >= a[cur].x && dp[cur][sum] == dp[cur - 1][sum - a[cur].x] + a[cur].y){
        dfs(cur - 1, sum - a[cur].x);
        cnt[cur] |= 2;
    }
}

void run(){
    cin >> n >> m; memset(dp, 0xc0, sizeof(dp));
    for(int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    for(int i = 0;i <= m;i++) dp[0][i] = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++){
            if(j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(j < a[i].x) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].x] + a[i].y);
        }
    }

    dfs(n, m);
    for(int i = 1;i <= n;i++){
        if(cnt[i] == 2) cout << 'A';
        else if(cnt[i] == 3) cout << 'B';
        else cout << 'C';
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

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
constexpr ll MAX = 5010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
ll result, pre[MAX][MAX], dp[MAX][MAX];

ll co(ll cur, ll cnt){
    ll ret = cnt ? pre[cur][cnt - 1] : 0;
    ret += (n - cnt) - (pre[cur][n - 1] - (cnt ? pre[cur][cnt - 1] : 0));
    return ret;
}

ll solve(ll cur, ll cnt){
    if(cur == -1) return 0;
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = INF;
    if(cnt != n) ret = min(ret, solve(cur, cnt + 1));
    ret = min(ret, solve(cur - 1, cnt) + co(cur, cnt));

    return ret;
}

void run(){
    cin >> n; memset(dp, -1, sizeof(dp));
    for(int i = 0;i < n;i++) cin >> st[i];

    for(int i = 0;i < n;i++){
        pre[i][0] = st[i][0] == '#';
        for(int j = 1;j < n;j++) pre[i][j] = pre[i][j - 1] + (st[i][j] == '#');
    }

    cout << solve(n - 1, 0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

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
constexpr ll MAX = 505; // SET MAX SIZE
constexpr ll MOD = 998244353;

const int MID = 502;
ll dp[MAX][MAX * MAX];

void run(){
    cin >> n; memset(dp, 0xc0, sizeof(dp));
    dp[0][0] = 0;

    int sum = 0;
    for(int i = 1;i <= n;i++){
        int w, h, b; cin >> w >> h >> b;
        sum += w;

        for(int j = 0;j <= sum;j++){
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + h);
            if(j >= w) dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + b);
        }
    }

    ll result = 0;
    for(int i = (sum + 1) / 2;i <= sum;i++){
        result = max(result, dp[n][i]);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
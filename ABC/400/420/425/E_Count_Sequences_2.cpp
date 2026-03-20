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

ll dp[5010][5010];
void init(){
    dp[0][0] = 1;
    for(int i = 1;i < 5010;i++){
        dp[i][0] = 1;
        for(int j = 1;j < 5010;j++){
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            dp[i][j] %= m;
        }
    }
}

void run(){
    cin >> n; ll result = 1, sum = 0;
    for(int i = 1;i <= n;i++){
        int v; cin >> v; sum += v;
        result *= dp[sum][v];
        result %= m;
    }

    cout << result << "\n";
}

int main() {
    fastio; 
    cin >> t >> m; init();
    while(t--) run(); 

    return 0;
}

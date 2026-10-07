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
constexpr ll MAX = 3010; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX];
int mx[MAX];
bool dp[MAX][MAX], chk[MAX];

void op(int y, int x){
    if(x < 0 || x >= n) return;
    if(!chk[x] && mx[x] <= y && y != n - 1){
        chk[x] = 1;
        for(int k = y;k >= 0;k--) dp[k][x] = 1;
    }

    if(st[y][x] == '#') return;
    dp[y][x] = 1;
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < n;i++) mx[i] = -1, chk[i] = 0;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            dp[i][j] = 0;
            if(st[i][j] == '.') continue;
            mx[j] = i;
        }
    }

    dp[n - 1][m - 1] = 1;
    for(int i = n - 1;i > 0;i--){
        for(int j = 0;j < n;j++){
            if(!dp[i][j]) continue;

            op(i - 1, j - 1);
            op(i - 1, j);
            op(i - 1, j + 1);
        }
    }
    
    for(int i = 0;i < n;i++) cout << dp[0][i];
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

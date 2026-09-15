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
constexpr ll MAX = 101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX][MAX];

void dfs(ll cy, ll cx, ll v){
    a[cy][cx] = v;
    if(v == n * n) return;
    if(!a[(cy + n - 1) % n][(cx + 1) % n]) dfs((cy + n - 1) % n, (cx + 1) % n, v + 1);
    else dfs((cy + 1) % n, cx, v + 1);
}

void run(){
    cin >> n;
    dfs(0, (n - 1) / 2, 1);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

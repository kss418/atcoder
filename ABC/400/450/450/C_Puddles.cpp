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

string st[MAX];
int seq, result;
int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
bool v[MAX][MAX];
bool out(int cy, int cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= m;
}

bool dfs(int cy, int cx){
    bool ret = 1; v[cy][cx] = 1;
    for(int i = 0;i < 4;i++){
        int ny = cy + dy[i], nx = cx + dx[i];
        if(out(ny, nx)){ ret = 0; continue; }
        if(st[ny][nx] == '#' || v[ny][nx]) continue;
        ret &= dfs(ny, nx);
    }

    return ret;
}

void run(){
    cin >> n >> m; 
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] == '#' || v[i][j]) continue;
            result += dfs(i, j);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
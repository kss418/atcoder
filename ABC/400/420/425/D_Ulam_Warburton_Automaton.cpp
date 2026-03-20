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
string st[MAX];
int result;

int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
bool out(int cy, int cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= m;
}

bool chk(int cy, int cx){
    if(st[cy][cx] == '#') return 0;

    int cnt = 0;
    for(int i = 0;i < 4;i++){
        int ny = cy + dy[i], nx = cx + dx[i];
        if(out(ny, nx)) continue;
        cnt += st[ny][nx] == '#';
    }

    return cnt == 1;
}

vector <pair<int, int>> arr;
vector <pair<int, int>> simulate(){
    vector <pair<int, int>> nxt;
    for(auto& [i, j] : arr){
        for(int k = 0;k < 4;k++){
            int ny = i + dy[k], nx = j + dx[k];
            if(out(ny, nx) || !chk(ny, nx)) continue;
            nxt.push_back({ny, nx});
        }
    }

    for(auto& [x, y] : nxt) st[x][y] = '#';
    return nxt;
}

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(st[i][j] != '#') continue;
            arr.push_back({i, j});
            result++;
        }
    }

    while(1){
        arr = simulate();
        if(arr.empty()) break;
        result += arr.size();
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

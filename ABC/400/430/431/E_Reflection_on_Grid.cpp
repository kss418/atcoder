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

string st[MAX];
struct node{
    int h, w, dir;
}; deque <pair <node, int>> q;
vector <vector <vector<int>>> d;

bool outrange(int ch, int cw){
    return ch < 0 || ch >= n || cw < 0 || cw >= m;
}

int nxt[3][4] = {
    {0, 1, 2, 3},
    {3, 2, 1, 0},
    {1, 0, 3, 2}
};

void run(){
    cin >> n >> m; 
    for(int i = 0;i < n;i++) cin >> st[i];

    vector <vector <vector<int>>> d; d.resize(n);
    for(int i = 0;i < n;i++) d[i].resize(m);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) d[i][j].assign(4, 0x3f3f3f3f);
    }

    for(int i = 0;i < 3;i++){
        int num = (i == st[0][0] - 'A') ? 0 : 1;
        d[0][0][nxt[i][1]] = num;
        q.push_back({{0, 0, nxt[i][1]}, num});
    }

    while(!q.empty()){
        auto [cur, cd] = q.front(); q.pop_front();
        auto& [ch, cw, cdir] = cur;
        if(d[ch][cw][cdir] != cd) continue;

        int nh = ch + (cdir == 2 ? 1 : cdir == 0 ? -1 : 0);
        int nw = cw + (cdir == 1 ? 1 : cdir == 3 ? -1 : 0);
        if(outrange(nh, nw)) continue;

        for(int i = 0;i < 3;i++){
            int nd = cd + (st[nh][nw] - 'A' != i);
            int ndir = nxt[i][cdir];
            if(d[nh][nw][ndir] <= nd) continue;
            d[nh][nw][ndir] = nd;

            if(st[nh][nw] - 'A' == i) {
                q.push_front({{nh, nw, ndir}, nd});
            }
            else {
                q.push_back({{nh, nw, ndir}, nd});
            }
        }
    }

    cout << min({d[n - 1][m - 1][1], d[n - 1][m - 1][1], d[n - 1][m - 1][1]}) << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}
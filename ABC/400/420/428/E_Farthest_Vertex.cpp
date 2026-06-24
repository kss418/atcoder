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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;

vector <int> adj[MAX];
pll dp[MAX], result[MAX];
pll solve(int cur, int pre = -1){
    pll& ret = dp[cur];
    if(ret != pll(-1, -1)) return ret; ret = {0, cur};

    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        pll tmp = solve(nxt, cur);
        tmp.x++;
        ret = max(ret, tmp);
    }

    return ret;
}

void reroot(int cur = 1, pll rev = {0, 1}, int pre = -1){
    result[cur] = max(solve(cur), rev);
    rev.x++;

    vector <pair<pll, int>> arr;
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        pll nr = solve(nxt); nr.x += 2;
        arr.push_back({nr, nxt});
    }

    sort(all(arr)); reverse(all(arr));
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;

        pll nr = rev;
        if(arr.size() >= 2 && arr[0].y == nxt) nr = max(nr, arr[1].x);
        else if(arr.size() >= 1 && arr[0].y != nxt) nr = max(nr, arr[0].x);
        reroot(nxt, nr, cur);
    }
}

void run(){
    cin >> n;
    for(int i = 1;i < n;i++){
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for(int i = 1;i <= n;i++) dp[i] = {-1, -1};
    solve(1); reroot();

    for(int i = 1;i <= n;i++) cout << result[i].y << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();

    return 0;
}

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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;

template <int M = 26>
class _ac {
private:
    vector<array<int, M>> adj;
    vector<int> f;
    vector<int> dep;
    vector<int> out;
    bool built;

    int tf(char ch) const {
        return ch - 'a';
    }

    int new_node() {
        adj.push_back(array<int, M>{});
        f.push_back(0);
        dep.push_back(0);
        out.push_back(0);
        return (int)adj.size() - 1;
    }

public:
    _ac() {
        clear();
    }

    void clear() {
        built = false;
        adj.clear();
        f.clear();
        dep.clear();
        out.clear();
        new_node();
    }

    void reserve(int max_node) {
        adj.reserve(max_node);
        f.reserve(max_node);
        dep.reserve(max_node);
        out.reserve(max_node);
    }

    int size() const {
        return (int)adj.size();
    }

    void insert(const string& s, int id) {
        assert(!built);

        int cur = 0;

        for(char ch : s) {
            int c = tf(ch);
            assert(0 <= c && c < M);

            if(!adj[cur][c]) {
                int nxt = new_node();
                adj[cur][c] = nxt;
                dep[nxt] = dep[cur] + 1;
            }

            cur = adj[cur][c];
        }

        out[cur] |= 1 << id;
    }

    void build() {
        assert(!built);
        built = true;

        queue<int> q;

        for(int c = 0; c < M; c++) {
            int nxt = adj[0][c];

            if(nxt) {
                f[nxt] = 0;
                q.push(nxt);
            }
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            out[cur] |= out[f[cur]];

            for(int c = 0; c < M; c++) {
                int nxt = adj[cur][c];

                if(!nxt) {
                    adj[cur][c] = adj[f[cur]][c];
                }
                else {
                    f[nxt] = adj[f[cur]][c];
                    q.push(nxt);
                }
            }
        }
    }

    int go(int state, int c) const {
        assert(built);
        assert(0 <= c && c < M);
        return adj[state][c];
    }

    int match_mask(int state) const {
        assert(built);
        return out[state];
    }
}; _ac ac;

string st[MAX];
ll dp[101][81][1 << 8], result;
void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> st[i], ac.insert(st[i], i);
    ac.build();

    dp[0][0][0] = 1;
    for(int i = 0;i < m;i++){
        for(int st = 0;st < ac.size();st++){
            for(int mask = 0;mask < (1 << n);mask++){
                for(char c = 0;c < 26;c++){
                    int nst = ac.go(st, c);
                    int nmask = mask | ac.match_mask(nst);
                    dp[i + 1][nst][nmask] += dp[i][st][mask];
                    dp[i + 1][nst][nmask] %= MOD;
                }
            }
        }
    }

    for(int i = 0;i < ac.size();i++){
        result += dp[m][i][(1 << n) - 1];
        result %= MOD;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();

    return 0;
}

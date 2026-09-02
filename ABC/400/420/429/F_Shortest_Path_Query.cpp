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
string st[3];

struct sp_policy{
    using dist = ll; using cost = ll;
    static dist add(const dist& d, const cost& w){ // dist + cost 
        return min(d + w, inf());
    }
    static bool leq(const dist& a, const dist& b){ // dist a <= dist b 
        return a <= b;
    }
    static dist inf(){ // ll -> INF, pll -> {INF, INF}, tll -> {INF, INF, INF} 
        return INF;
    }
    static dist zero(){ // ll -> 0, pll -> {0, 0}, tll -> {0, 0, 0} 
        return 0;
    }
};

template <class policy = sp_policy>
class _floyd { 
private:
    using dist = typename policy::dist; using cost = typename policy::cost;
    vector <vector<dist>> d; vector <vector<int>> nxt; 
    int n; bool built = 0;

    static bool less(const dist& a, const dist& b){ return policy::leq(a, b) && !policy::leq(b, a); }
    static bool eq(const dist& a, const dist& b){ return policy::leq(a, b) && policy::leq(b, a); }
    void chk(int st, int en) const{ assert(built); assert(st >= 0 && st <= n); assert(en >= 0 && en <= n); }
public:
    _floyd(int n = 0){ clear(n); } // O(n^2)
    void clear(int n){ // O(n^2)
        this->n = n; built = 0;
        d.assign(n + 1, vector<dist>(n + 1, policy::inf()));
        nxt.assign(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++){
            d[i][i] = policy::zero();
            nxt[i][i] = i;
        }
    }

    void add(int st, int en, cost c) { // O(1)
        addsol(st, en, c); addsol(en, st, c);
    }

    void addsol(int st, int en, cost c) { // O(1)
        built = 0;
        if(!less(c, d[st][en])) return;
        d[st][en] = c; nxt[st][en] = en;
    }

    void init() { // O(n^3)
        built = 1;
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist nd = policy::add(d[i][k], d[k][j]);
                    if (policy::leq(d[i][j], nd)) continue;
                    d[i][j] = nd; nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    dist ret(int st, int en) const{ // O(1)
        chk(st, en);
        return d[st][en];
    }

    bool reachable(int st, int en) const{ // O(1)
        chk(st, en);
        return !eq(d[st][en], policy::inf());
    }

    template<class F>
    void it_path(int st, int en, const F& f) const{ // O(n)
        chk(st, en); assert(reachable(st, en));
        for(int cur = st;; cur = nxt[cur][en]){
            f(cur);
            if(cur == en) break;
        }
    }
};

struct monoid{
    struct node {
        array <array <ll, 3>, 3> dist;
        int l, r;

        node(const array <array<ll, 3>, 3> dist = {{
            {INF, INF, INF},
            {INF, INF, INF},
            {INF, INF, INF}
        }}, int idx = 0) : dist(dist), l(idx), r(idx){}
    };
    static node op(const node& l, const node& r){
        if(!l.l) return r;
        if(!r.l) return l;

        node ret;
        ret.l = l.l; ret.r = r.r;

        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                ret.dist[i][j] = INF;
                for(int k = 0;k < 3;k++){
                    if(l.dist[i][k] == INF || r.dist[k][j] == INF) continue;
                    ret.dist[i][j] = min(ret.dist[i][j], l.dist[i][k] + r.dist[k][j] + 1);
                }
            }
        }

        return ret;
    }
};

template <class policy = monoid>
class _seg {
public:
    using node = typename policy::node;
    node op(const node& l, const node& r) const{ return policy::op(l, r); }
    node id() const{ return node(); }
private:
    int n, sz; vector <node> seg;
    node join(const node& a, const node& b, bool right) const{ return right ? op(a, b) : op(b, a); }
    template<class F>
    int bisect(int p, bool right, const F& f) {
        assert(0 <= p && p <= n); assert(f(id()));
        if(right) { if (p == n) return n; }
        else { if (p == 0) return 0; }
        int i = right ? (p + sz) : (p + 1 + sz); node v = id();
        while(1){
            if(!right) --i;
            if(right) while ((i & 1) == 0) i >>= 1;
            if(!right) while (i > 1 && (i & 1)) i >>= 1;
            node tmp1 = join(v, seg[i], right);
            if (!f(tmp1)) {
                while (i < sz) {
                    i = (i << 1) | (!right);         
                    node tmp2 = join(v, seg[i], right);
                    if(f(tmp2)){ v = tmp2; i += right ? 1 : -1; }
                }
                return right ? (i - sz - 1) : (i + 1 - sz);
            }
            v = tmp1;
            if(right) ++i; if((i & -i) == i) break;
        }
        return right ? n : 0;
    }
public:
    _seg(int n = 0){ clear(n); } // O(n)
    _seg(span<const node> arr){ build(arr); } // O(n)
    void clear(int n){ // O(n)
        this->n = n;
        sz = 1; while(sz < n + 1) sz <<= 1;
        seg.assign(2 * sz, id());
    }

    void build(span<const node> arr){ // O(n)
        if(arr.empty()){ clear(0); return; }
        clear((int)arr.size() - 1);
        for(int i = 0;i < (int)arr.size();i++) seg[i + sz] = arr[i];
        for(int i = sz - 1;i >= 1;i--) seg[i] = op(seg[i << 1], seg[i << 1 | 1]);
    }

    node query(int st, int en){ // O(log n)
        st = max(0, st); en = min(n, en);
        if(st > en) return id();
        node l = id(), r = id();
        st += sz; en += sz;
        while(st <= en){
            if(st & 1) l = op(l, seg[st++]);
            if(!(en & 1)) r = op(seg[en--], r);
            st >>= 1; en >>= 1; 
        }
        return op(l, r);
    }

    void set(int idx, const node& v){ // O(log n)
        if(idx < 0 || idx > n) return;
        int p = idx + sz; seg[p] = v;
        for(p >>= 1; p; p >>= 1) seg[p] = op(seg[p << 1], seg[p << 1 | 1]);
    }

    template<class F>
    int max_right(int l, const F& f){ return bisect(l, 1, f); } // O(log n)

    template<class F>
    int min_left(int r, const F& f){  return bisect(r, 0, f); } // O(log n)
}; _seg seg;

void run(){
    cin >> n; seg.clear(n);
    for(int i = 0;i < 3;i++) cin >> st[i];
    for(int i = 0;i < n;i++){
        array <array <ll, 3>, 3> dist = {{
            {INF, INF, INF},
            {INF, INF, INF},
            {INF, INF, INF}
        }};

        _floyd floyd(3);
        for(int j = 0;j < 2;j++){
            if(st[j][i] == '#' || st[j + 1][i] == '#') continue;
            floyd.add(j + 1, j + 2, 1);
        }

        floyd.init();
        for(int i = 1;i <= 3;i++){
            for(int j = 1;j <= 3;j++) dist[i - 1][j - 1] = floyd.ret(i, j);
        }

        for(int j = 0;j < 3;j++){
            if(st[j][i] != '#') continue;
            for(int k = 0;k < 3;k++) dist[j][k] = dist[k][j] = INF;
        }
        seg.set(i + 1, {dist, i + 1});
    }

    cin >> m;
    while(m--){
        int y, x; cin >> y >> x;
        if(st[y - 1][x - 1] == '#') st[y - 1][x - 1] = '.';
        else st[y - 1][x - 1] = '#';

        array <array <ll, 3>, 3> dist = {{
            {INF, INF, INF},
            {INF, INF, INF},
            {INF, INF, INF}
        }};

        _floyd floyd(3);
        for(int j = 0;j < 2;j++){
            if(st[j][x - 1] == '#' || st[j + 1][x - 1] == '#') continue;
            floyd.add(j + 1, j + 2, 1);
        }

        floyd.init();
        for(int i = 1;i <= 3;i++){
            for(int j = 1;j <= 3;j++) dist[i - 1][j - 1] = floyd.ret(i, j);
        }

        for(int j = 0;j < 3;j++){
            if(st[j][x - 1] != '#') continue;
            for(int k = 0;k < 3;k++) dist[j][k] = dist[k][j] = INF;
        }

        seg.set(x, {dist, x});

        ll ret = seg.query(1, n).dist[0][2];
        cout << (ret == INF ? -1 : ret) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

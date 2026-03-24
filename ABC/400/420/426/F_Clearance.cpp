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

struct action{
    struct node {
        ll v; int sz;
        node(ll v = 0, int sz = 0) : v(v), sz(sz){}
    };
    struct lazy{
        ll v;
        lazy(ll v = 0) : v(v){}
    };
    static node op(const node& l, const node& r){
        return node{
            l.v + r.v,
            l.sz + r.sz
        };
    }
    static bool is_lz_id(const lazy& now){ return now.v == 0; }
    static void apply(node& seg, const lazy& lz){ seg.v += lz.v * seg.sz; }
    static void compose(lazy& s, const lazy& p){ s.v += p.v; }
};

template <class policy = action>
class _prop { 
public:
    using node = typename policy::node;
    using lazy = typename policy::lazy;
    node op(const node& l, const node& r) const{ return policy::op(l, r); }
    node id() const{ return node(); }
private:
    vector <node> seg; vector <lazy> lz; int sz, h, n;
    lazy lz_id() const{ return lazy(); }
    bool is_lz_id(const lazy& now) const{ return policy::is_lz_id(now); }
    void prop(node& seg, const lazy& lz) const{ policy::apply(seg, lz); }
    void comp(lazy& s, const lazy& p) const{ policy::compose(s, p); }
    node join(const node& a, const node& b, bool right) const{ return right ? op(a, b) : op(b, a); }

    void push(int idx){
        if(is_lz_id(lz[idx])) return;
        apply(idx << 1, lz[idx]);
        apply(idx << 1 | 1, lz[idx]);
        lz[idx] = lz_id();
    }

    void propagate(int idx){
        for(int i = h;i > 0;i--){
            int cur = idx >> i;
            push(cur);
        }
    }

    void apply(int idx, const lazy& now){
        prop(seg[idx], now);
        if(idx < sz) comp(lz[idx], now); 
    }

    void rebuild(int idx){
        while(idx > 1){
            idx >>= 1;
            seg[idx] = op(seg[idx << 1], seg[idx << 1 | 1]);
            if(is_lz_id(lz[idx])) continue;
            prop(seg[idx], lz[idx]);
        }
    }

    template<class F>
    int bisect(int p, bool right, const F& f) {
        assert(0 <= p && p <= n); assert(f(id()));
        if(right) { if (p == n) return n; }
        else { if (p == 0) return 0; }
        int i = right ? (p + sz) : (p + 1 + sz);
        if(right) propagate(i); else propagate(i - 1);
        node v = id();
        while(1){
            if(!right) --i;
            if(right) while ((i & 1) == 0) i >>= 1;
            if(!right) while (i > 1 && (i & 1)) i >>= 1;
            node tmp1 = join(v, seg[i], right);
            if (!f(tmp1)) {
                while (i < sz) {
                    push(i);
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
    _prop(int n = 0){ clear(n); } // O(n)
    _prop(span<const node> arr){ build(arr); } // O(n)
    void clear(int n){ // O(n)
        this->n = n;
        sz = 1; while(sz < n + 1) sz <<= 1;
        h = __lg(sz);
        seg.assign(2 * sz, id());
        lz.assign(2 * sz, lz_id());
    }

    void build(span<const node> arr){ // O(n)
        if(arr.empty()){ clear(0); return; }
        clear((int)arr.size() - 1);
        for(int i = 0;i < (int)arr.size();i++) seg[i + sz] = arr[i];
        for(int i = sz - 1;i >= 1;i--) seg[i] = op(seg[i << 1], seg[i << 1 | 1]);
    }

    node query(int idx){ return query(idx, idx); } // O(log n)
    node query(int st, int en) { // O(log n)
        st = max(0, st); en = min(n, en);
        if(st > en) return id();

        int l = (int)st + sz, r = (int)en + sz;
        propagate(l); propagate(r);

        node nl = id(), nr = id();
        while(l <= r){
            if(l & 1) nl = op(nl, seg[l++]);
            if(!(r & 1)) nr = op(seg[r--], nr);
            l >>= 1; r >>= 1;
        }

        return op(nl, nr);
    }

    void update(int idx, const lazy& lz){ update(idx, idx, lz); } // O(log n)
    void update(int st, int en, const lazy& lz){ // O(log n)
        st = max(0, st); en = min(n, en);
        if(st > en) return;

        int l = (int)st + sz, r = (int)en + sz;
        int tl = l, tr = r;
        propagate(l); propagate(r);

        while(l <= r){
            if(l & 1) apply(l++, lz);
            if(!(r & 1)) apply(r--, lz);
            l >>= 1; r >>= 1;
        }
        
        rebuild(tl); rebuild(tr);
    }

    template<class F>
    int max_right(int l, const F& f){ return bisect(l, 1, f); } // O(log n)

    template<class F>
    int min_left(int r, const F& f){  return bisect(r, 0, f); } // O(log n)
}; _prop seg;

template <class policy>
concept has_inv = requires(const typename policy::node& a){
    { policy::inv(a) } -> std::same_as<typename policy::node>;
};

struct group{
    struct node{
        ll v;
        node(ll v = 0) : v(v){}
    };
    static node op(const node& l, const node& r){
        return {l.v + r.v};
    }
    static node inv(const node& a){
        return {-a.v};
    }
};

template <class policy = group>
class _fw{ // 0-based index
private:
    using node = typename policy::node;
    vector <node> bit; int n;
    node op(const node& l, const node& r) const{ return policy::op(l, r); }
    node id() const{ return node(); }
    node inv(const node& a) const{ return policy::inv(a); }
public:
    _fw(int n = 0){ clear(n); } // O(n)
    _fw(span<const node> arr){ build(arr); } // O(n)
    void clear(int n){ // O(n)
        this->n = n;
        bit.assign(n + 2, id());
    }

    void build(span<const node> arr){ // O(n)
        if(arr.empty()){ clear(0); return; }
        clear((int)arr.size() - 1);
        for(int i = 0;i <= n;i++) bit[i + 1] = arr[i];
        for(int i = 1;i <= n + 1;i++){
            int j = i + (i & -i);
            if(j <= n + 1) bit[j] = op(bit[j], bit[i]);
        }
    }

    // range query -> need inv
    node query(int idx) requires has_inv<policy> { return query(idx, idx); } // O(log n)
    node query(int l, int r) requires has_inv<policy> { // O(log n)
        l = max(l, 0); r = min(r, n);
        if(l > r) return id();
        return op(pre(r), inv(pre(l - 1))); 
    }

    // return 0 ~ idx
    node pre(int idx){ // O(log n)
        node ret = id(); idx = min(idx, n);
        for(int i = idx + 1;i > 0;i -= i & -i) ret = op(ret, bit[i]);
        return ret;
    }

    void set(int idx, const node& v) requires has_inv<policy> { // O(log n)
        if(idx < 0 || idx > n) return;
        node cur = query(idx, idx), d = op(v, inv(cur));         
        update(idx, d);                
    }

    void update(int idx, const node& v){ // O(log n)
        if(idx < 0 || idx > n) return;
        for(int i = idx + 1;i <= n + 1;i += i & -i) bit[i] = op(bit[i], v);
    }
}; _fw fw;

tll query[MAX];
void apply(int idx){
    auto& [l, r, v] = query[idx];
    seg.update(l, r, v);
}

action::node in[MAX];
class _pbs{
public:
    ll lo, hi;
    vector <ll> l, r;
    vector <vector <ll>> arr;

    _pbs(){}
    _pbs(ll lo, ll hi) : lo(lo), hi(hi){}

    class query{ 
    public:
        ll v;
    }; vector <query> q;
    void add(query a){ q.push_back(a); }

    void clear(){
        for(ll i = lo;i <= hi;i++) arr[i].clear();
    }

    bool f(ll cur, ll idx){ // 결정 함수
        query& now = q[idx];
        return seg.query(idx + 1).v > now.v; 
    }

    void init(){
        arr.resize(hi + 1);
        l.resize(q.size(), lo); r.resize(q.size(), hi);

        while(1){
            clear(); bool flag = 0;
            for(int i = 0;i < q.size();i++){
                if(l[i] >= r[i]) continue;
                ll mid = (l[i] + r[i]) >> 1ll;
                arr[mid].push_back(i); flag = 1;
            }
            if(!flag) break;
            
            seg.build(in);
            int num = 1;
            for(ll mid = lo;mid <= hi;mid++){
                while(num <= min<int>(mid, m)){
                    apply(num);
                    num++;
                }

                for(auto& idx : arr[mid]){
                    if(!f(mid, idx)) l[idx] = mid + 1;
                    else r[idx] = mid;
                }
            }
        }
    }
};

ll a[MAX];
deque <pll> q;
void run(){
    cin >> n; fw.clear(n);
    for(int i = 1;i <= n;i++) cin >> a[i], fw.set(i, 1);
    for(int i = 1;i <= n;i++) in[i] = {0, 1};

    cin >> m; _pbs pbs(1, m + 1);
    for(int i = 1;i <= n;i++) pbs.add({a[i]});
    for(int i = 1;i <= m;i++){
        int l, r, v; cin >> l >> r >> v;
        query[i] = {l, r, v};
    }

    pbs.init();
    for(int i = 0;i < pbs.l.size();i++) q.push_back({pbs.l[i], i + 1});
    sort(all(q)); 
    
    for(int i = 1;i <= n;i++) in[i] = {a[i], 1};
    seg.build(in);

    for(int i = 1;i <= m;i++){
        ll sum = 0;
        while(!q.empty() && q.front().x <= i){
            auto& [v, idx] = q.front(); q.pop_front();
            fw.set(idx, 0); sum += seg.query(idx).v;
        }

        auto& [l, r, v] = query[i];
        int cnt = fw.query(l, r).v;
        seg.update(l, r, -v);
        cout << cnt * v + sum << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

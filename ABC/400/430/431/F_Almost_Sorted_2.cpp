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

int c[1010101];
ll sum;

class _mint{
public:
    ll mod, v;
    _mint(ll v = 0, ll mod = 1) : mod(mod), v(norm(v, mod)) {}
    static ll norm(ll x, ll m){ x %= m; return x < 0 ? x + m : x; }
    static tll gcd(ll a, ll b){
        if (b == 0) return {a, 1, 0};
        auto [g, x, y] = gcd(b, a % b);
        return {g, y, x - (a / b) * y};
    }

    _mint inv() const{
        assert(v);
        auto [g, x, y] = gcd(v, mod);
        assert(g == 1 || g == -1);
        if(g == -1) x *= -1;
        return _mint(x, mod);
    }

    _mint pow(ll e) const{
        assert(e >= 0);
        _mint base = *this, ret(1, mod);
        while(e){
            if(e & 1) ret *= base;
            base *= base; e >>= 1ll;
        }
        return ret;
    }

    _mint& operator+=(const _mint& ot){
        assert(mod == ot.mod);
        v += ot.v;
        if (v >= mod) v -= mod;
        return *this;
    }

    _mint& operator-=(const _mint& ot){
        assert(mod == ot.mod);
        v -= ot.v;
        if (v < 0) v += mod;
        return *this;
    }

    _mint& operator*=(const _mint& ot){
        assert(mod == ot.mod);
        v = (ll)((i128)v * ot.v % mod);
        return *this;
    }
    _mint& operator/=(const _mint& ot){ return (*this) *= ot.inv(); }

    friend _mint operator+(_mint a, const _mint& b){ return a += b; }
    friend _mint operator-(_mint a, const _mint& b){ return a -= b; }
    friend _mint operator*(_mint a, const _mint& b){ return a *= b; }
    friend _mint operator/(_mint a, const _mint& b){ return a /= b; }
    _mint& operator+=(ll b){ return (*this) += _mint(b, mod); }
    _mint& operator-=(ll b){ return (*this) -= _mint(b, mod); }
    _mint& operator*=(ll b){ return (*this) *= _mint(b, mod); }
    _mint& operator/=(ll b){ return (*this) /= _mint(b, mod); }
    friend _mint operator+(_mint a, ll b){ return a += b; }
    friend _mint operator-(_mint a, ll b){ return a -= b; }
    friend _mint operator*(_mint a, ll b){ return a *= b; }
    friend _mint operator/(_mint a, ll b){ return a /= b; }
    friend ostream& operator<<(ostream& os, const _mint& a){ return os << a.v; }
}; _mint result(1, MOD);

class _comb{
public:
    vector <_mint> fac, inv; int n; ll m; // m == prime
    _comb(int n, ll m = 998244353) : n(n), m(m), fac(n + 1), inv(n + 1){ 
        assert(n < m);
        fac[0] = _mint(1, m);
        for(int i = 1;i <= n;i++) fac[i] = fac[i - 1] * i;
        inv[n] = fac[n].pow(m - 2);
        for(int i = n - 1;i >= 0;i--) inv[i] = inv[i + 1] * (i + 1);
    }

    ll ret(ll n, ll r){
        if(n < 0 || r < 0 || n < r) return 0;
        return (fac[n] * inv[r] * inv[n - r]).v;
    }
}; _comb comb(1010101);

void run(){
    cin >> n >> m; 
    for(int i = 1;i <= n;i++){
        cin >> k; c[k]++;
    }

    for(int i = 1;i < 1010101;i++){
        sum += c[i];
        if(i > m) sum -= c[i - m - 1];

        if(!c[i]) continue;
        result *= comb.ret(sum, c[i]);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
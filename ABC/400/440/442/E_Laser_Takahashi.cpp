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

template <typename T = pll>
class _angle_sort{
private:
    using i128 = __int128_t;
    static i128 dx(const T& p, ll cx){ return (i128)p.x - cx; }
    static i128 dy(const T& p, ll cy){ return (i128)p.y - cy; }

    static int half_ccw(i128 x, i128 y){ return (y > 0 || (y == 0 && x >= 0)) ? 0 : 1; }
    static int half_cw(i128 x, i128 y){ return (y < 0 || (y == 0 && x >= 0)) ? 0 : 1; }
public:
    static void sort(span<T> arr, ll cx = 0, ll cy = 0, bool is_clock = false){
        std::sort(arr.begin(), arr.end(), [&](const T& a, const T& b){
            i128 ax = dx(a, cx), ay = dy(a, cy);
            i128 bx = dx(b, cx), by = dy(b, cy);

            int ha = is_clock ? half_cw(ax, ay) : half_ccw(ax, ay);
            int hb = is_clock ? half_cw(bx, by) : half_ccw(bx, by);

            if(ha != hb) return ha < hb;
            i128 cross = ax * by - ay * bx;
            if(cross) return is_clock ? cross < 0 : cross > 0;

            i128 da = ax * ax + ay * ay;
            i128 db = bx * bx + by * by;
            return da < db;
        });
    }

    static bool is_same(const T& a, const T& b, ll cx = 0, ll cy = 0){
        i128 ax = dx(a, cx), ay = dy(a, cy);
        i128 bx = dx(b, cx), by = dy(b, cy);
        return ax * by - ay * bx == 0 && ax * bx + ay * by > 0;
    }
};

struct point{
    ll x, y, idx;
};
point a[MAX];
vector <point> arr;
ll pos[MAX], pre[2 * MAX], cnt[MAX];

void run(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i].x >> a[i].y, a[i].idx = i + 1;
    _angle_sort<point>::sort(span(a, a + n), 0, 0, 1);

    arr.push_back(a[0]); pos[a[0].idx] = 0;
    cnt[0] = 1;

    for(int i = 1;i < n;i++){
        if(_angle_sort<point>::is_same(arr.back(), a[i])){
            cnt[arr.size() - 1]++;
            pos[a[i].idx] = arr.size() - 1;
            continue;
        }

        arr.push_back(a[i]);
        cnt[arr.size() - 1] = 1;
        pos[a[i].idx] = arr.size() - 1;
    }

    pre[0] = cnt[0];
    for(int i = 1;i < arr.size();i++) pre[i] += pre[i - 1] + cnt[i];
    for(int i = arr.size(); i < 2 * arr.size();i++) pre[i] = pre[i - 1] + cnt[i - arr.size()];
    
    while(m--){
        int s, e; cin >> s >> e;
        s = pos[s]; e = pos[e];
        if(s > e) e += arr.size();
        cout << pre[e] - (s ? pre[s - 1] : 0) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

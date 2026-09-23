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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];
struct node{
    array <ll, 50> arr{};
    bool operator < (const node& ot) const{
        return arr < ot.arr;
    }
}; map <node, bool> mp;

priority_queue <pair<ll, node>> pq;
vector <ll> result;

void run(){
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a, a + n); reverse(a, a + n);

    node st; st.arr[0] = m;
    pq.push({a[0] * m, st});

    while(!pq.empty()){
        auto [cd, cur] = pq.top(); pq.pop();
        result.push_back(cd);
        if(result.size() == k) break;

        for(int i = 0;i < n - 1;i++){
            if(!cur.arr[i]) continue;
            cur.arr[i]--; cur.arr[i + 1]++;
            if(!mp.count(cur)){
                pq.push({cd - a[i] + a[i + 1], cur});
                mp[cur] = 1;
            }
            cur.arr[i]++; cur.arr[i + 1]--;
        }
    }

    for(auto& i : result) cout << i << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

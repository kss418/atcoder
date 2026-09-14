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
set <ll> ms[MAX];
map <ll, ll> ind;
priority_queue <pll, vector<pll>, greater<pll>> pq;
map <ll, vector<ll>> arr;
map <ll, bool> v;
ll result;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        ll a, b; cin >> a >> b;
        ll l = a - b, r = a + b;
        ind[l]++; ind[r]++;
        arr[l].push_back(r);
        arr[r].push_back(l);
    }

    for(auto& [idx, v] : ind) pq.push({v, idx});
    while(!pq.empty()){
        auto [cv, idx] = pq.top(); pq.pop();
        if(ind[idx] != cv) continue;
        if(ind[idx] <= 0 || v.count(idx)) continue;
        result++; v[idx] = 1;

        ll mx = 0, tmp = INF;
        for(auto& nxt : arr[idx]){
            if(v.count(nxt)) continue;
            if(mx >= ind[nxt]) continue;
            mx = ind[nxt]; tmp = nxt;
        }

        if(tmp == INF) continue;
        ind[tmp]--; pq.push({ind[tmp], tmp});
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

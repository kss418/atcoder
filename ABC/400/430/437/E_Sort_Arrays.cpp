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
ll org[MAX], seq;
map <ll, ll> mp[MAX];
vector <ll> arr[MAX];

ll nxt(ll pre, ll x, ll idx){
    ll num = org[pre];
    if(!mp[num].count(x)) mp[num][x] = ++seq;
    arr[mp[num][x]].push_back(idx);
    return mp[num][x];
}

void dfs(ll cur){
    if(cur) for(auto& i : arr[cur]) cout << i << " ";
    for(auto& [nv, nxt] : mp[cur]) dfs(nxt);
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        ll x, y; cin >> x >> y;
        org[i] = nxt(x, y, i);
    }

    dfs(0);
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

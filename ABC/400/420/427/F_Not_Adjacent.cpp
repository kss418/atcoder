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
constexpr ll MAX = 66; // SET MAX SIZE
constexpr ll MOD = 998244353;

int a[MAX];
vector <pair<int, bool>> pre, suf;
unordered_map <int, int> mp[2];
vector <int> arr[2];

void bt1(int idx, int sum, bool flag){
    arr[flag].push_back(sum);
    for(int i = idx;i < pre.size();i++){
        int ns = sum + pre[i].x;
        if(ns >= m) ns -= m;
        bt1(i + 2, ns, flag | pre[i].y);
    }
}

void bt2(int idx, int sum, bool flag){
    mp[flag][sum]++;
    for(int i = idx;i < suf.size();i++){
        int ns = sum + suf[i].x;
        if(ns >= m) ns -= m;
        bt2(i + 2, ns, flag | suf[i].y);
    }
}

void run(){
    cin >> n >> m; 
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n == 1){
        cout << ((a[1] == 0) + 1);
        return;
    }

    for(int i = 1;i < n / 2;i++) pre.push_back({a[i], 0});
    pre.push_back({a[n / 2], 1});

    suf.push_back({a[n / 2 + 1], 1});
    for(int i = n / 2 + 2;i <= n;i++) suf.push_back({a[i], 0});

    bt1(0, 0, 0); bt2(0, 0, 0);

    ll result = 0;
    for(auto& i : arr[0]){
        ll cnt = 0;
        if(i) cnt += mp[0][m - i] + mp[1][m - i];
        else cnt += mp[0][0] + mp[1][0];
        result += cnt;
    }

    for(auto& i : arr[1]){
        ll cnt = 0;
        if(i) cnt += mp[0][m - i];
        else cnt += mp[0][0];
        result += cnt;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
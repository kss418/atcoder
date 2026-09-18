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
vector <vector<ll>> result;
vector <ll> arr;
ll sum;

void bt(){
    ll sz = arr.size();
    if(sz == n - 1){
        arr.push_back(m - sum);
        vector <ll> tmp = arr;
        reverse(all(tmp));
        result.push_back(tmp);
        arr.pop_back();
        return;
    }

    for(int i = 0;i <= m;i++){
        if(sum + (n - sz) * i > m) break;
        sum += (n - sz) * i;
        arr.push_back(i);
        bt();
        arr.pop_back();
        sum -= (n - sz) * i;
    }
}

void run(){
    cin >> n >> m; 
    bt();

    sort(all(result));
    for(auto& i : result){
        for(auto& j : i) cout << j << " ";
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
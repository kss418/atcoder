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
int cnt[10101010];
vector <int> result;

void run(){
    cin >> n;
    for(int i = 1;i * i <= n;i++){
        for(int j = i + 1;j * j <= n;j++){
            if(i * i + j * j > n) break;
            int now = i * i + j * j;
            cnt[now]++;
        }
    }

    for(int i = 1;i <= n;i++){
        if(cnt[i] != 1) continue;
        result.push_back(i);
    }

    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

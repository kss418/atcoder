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
constexpr ll MAX = 11; // SET MAX SIZE
constexpr ll MOD = 998244353;

ll a[MAX]; bool use[MAX];
void run(){
    cin >> n; bool result = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == -1) continue;
        if(use[a[i]]) result = 0;
        use[a[i]] = 1;
    }

    cout << (result ? "Yes" : "No") << "\n";
    if(!result) return;
    for(int i = 1;i <= n;i++){
        if(a[i] != -1){ cout << a[i] << " "; continue; }
        for(int j = 1;j <= n;j++){
            if(use[j]) continue;
            use[j] = 1; cout << j << " ";
            break;
        }
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

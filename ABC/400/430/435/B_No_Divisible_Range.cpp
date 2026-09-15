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
constexpr ll MAX = 55; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll pre[MAX], a[MAX], result;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for(int l = 1;l <= n;l++){
        for(int r = l;r <= n;r++){
            ll sum = pre[r] - pre[l - 1];
            bool flag = 1;
            for(int i = l;i <= r;i++) flag &= ((sum % a[i]) != 0);
            result += flag;
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

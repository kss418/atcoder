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
constexpr ll MAX = 2010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll sum[MAX][MAX], pre[MAX][MAX], a[MAX][MAX];
ll l[201010], r[201010], u[201010], d[201010], zero;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> u[i] >> d[i] >> l[i] >> r[i];

        sum[u[i]][l[i]]++; sum[d[i] + 1][r[i] + 1]++;
        sum[d[i] + 1][l[i]]--; sum[u[i]][r[i] + 1]--;
    }

    ll now = 0;
    for(int i = 1;i <= 2000;i++){
        for(int j = 1;j <= 2000;j++) sum[i][j] += sum[i][j - 1];
    }

    for(int i = 1;i <= 2000;i++){
        for(int j = 1;j <= 2000;j++) sum[i][j] += sum[i - 1][j];
    }

    for(int i = 1;i <= 2000;i++){
        for(int j = 1;j <= 2000;j++){
            zero += (sum[i][j] == 0);
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (sum[i][j] == 1);
        }
    }

    for(int i = 1;i <= n;i++){
        ll now = zero + pre[d[i]][r[i]];
        now -= pre[u[i] - 1][r[i]] + pre[d[i]][l[i] - 1];
        now += pre[u[i] - 1][l[i] - 1];
        cout << now << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

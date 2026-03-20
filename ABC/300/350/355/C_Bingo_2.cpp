#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 2010; // PLZ CHK!
constexpr ll MOD = 998244353;
ll a[201010], x[MAX], y[MAX];
ll pa, ma;

bool chk(ll cx, ll cy){
    if(x[cx] == n) return 1;
    if(y[cy] == n) return 1;
    if(pa == n) return 1;
    if(ma == n) return 1;
    return 0;
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> a[i];

    for(int i = 1;i <= m;i++){
        ll cx = (a[i] - 1) % n + 1;
        ll cy = (a[i] - 1) / n + 1;

        x[cx]++; y[cy]++;
        if(cx == cy) pa++;
        if(cx + cy == n + 1) ma++;

        if(!chk(cx, cy)) continue;
        cout << i; return 0;
    }

    cout << -1;
    
     
    return 0;
}
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
constexpr ll MAX = 101; // PLZ CHK!
constexpr ll MOD = 998244353;
ll a[MAX], b[MAX];
pll c[2 * MAX];

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i], c[i] = {a[i], 1};
    for(int i = 1;i <= m;i++) cin >> b[i], c[n + i] = {b[i], 0};
    sort(c + 1, c + n + m + 1);

    ll result = 0;
    for(int i = 1;i < n + m;i++){
        if(c[i].y && c[i + 1].y) result = 1;
    }
    
    if(result) cout << "Yes";
    else cout << "No";

     
    return 0;
}
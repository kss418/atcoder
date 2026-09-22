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
ll result;
stack <pll> stk;

void run(){
    cin >> n; result = n;
    for(int i = 1;i <= n;i++){
        ll v; cin >> v;
        while(!stk.empty() && stk.top().y == 4){
            stk.pop();
            result -= 4;
        }

        if(!stk.empty() && stk.top().x == v){
            ll c = stk.top().y;
            stk.pop();
            stk.push({v, c + 1});
        }
        else stk.push({v, 1});
    }

    while(!stk.empty() && stk.top().y == 4){
        stk.pop();
        result -= 4;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

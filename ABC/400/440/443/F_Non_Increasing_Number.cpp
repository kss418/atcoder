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
constexpr ll MAX = 3010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <tll> arr;
deque <ll> q;
bool use[MAX][10];

void push(int cur, int v, int p = -1){
    if(use[cur][v]) return; use[cur][v] = 1;
    arr.push_back({cur, v, p});
    q.push_back(arr.size() - 1);
}

void run(){
    cin >> n;
    for(int i = 1;i <= 9;i++) push(i % n, i);

    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        auto [mod, v, pre] = arr[cur];

        if(!mod){
            vector <int> result;
            while(cur != -1){
                auto [ci, cv, cp] = arr[cur];
                result.push_back(cv);
                cur = cp;
            }

            reverse(all(result));
            for(auto& i : result) cout << i;
            return;
        }

        for(int i = v;i <= 9;i++){
            push((10 * mod + i) % n, i, cur);
        }
    }   

    cout << -1;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

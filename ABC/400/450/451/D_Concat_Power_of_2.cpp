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

vector <int> arr, org;
unordered_map <int, bool> v;
deque <int> q;
void run(){
    cin >> n;
    for(int i = 1;i <= 1e9 + 1;i <<= 1){
        org.push_back(i);
        q.push_back(i); v[i] = 1;
    }

    while(!q.empty()){
        int cur = q.front(); q.pop_front();
        arr.push_back(cur);
        for(auto& i : org){
            ll tmp = stoll(to_string(cur) + to_string(i));
            if(tmp >= 1e9) break;
            if(v.count(tmp)) continue;
            q.push_back(tmp); v[tmp] = 1;
        }
    }

    sort(all(arr));
    cout << arr[n - 1];
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

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
constexpr ll MAX = 501010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> arr, cnt, num;

void run(){
    cin >> n >> m >> k; 
    for(int i = 1;i <= n;i++){
        ll v; cin >> v;
        arr.push_back(v);
    }
    sort(all(arr));

    ll idx = 0;
    while(idx < n){
        num.push_back(arr[idx]);

        ll nxt = idx + 1;
        while(nxt < n){
            if(arr[idx] != arr[nxt]) break;
            nxt++;
        }

        cnt.push_back(nxt - idx);
        idx = nxt;
    }

    idx = 0;
    ll sum = 0, result = 0;
    for(int i = 0;i < num.size();i++){
        while(sum < k){
            sum += cnt[idx];
            idx++;
            if(idx >= num.size()) idx -= num.size();
        }

        if(!i) result += (m + num[0] - num.back()) * sum;
        else result += (num[i] - num[i - 1]) * sum;
        sum -= cnt[i];
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
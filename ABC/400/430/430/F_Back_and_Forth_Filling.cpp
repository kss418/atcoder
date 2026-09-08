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
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
int pre[MAX], suf[MAX], arr[MAX];

void run(){
    cin >> n >> s;
    for(int i = 0;i <= n;i++) suf[i] = pre[i] = arr[i] = 0;

    pre[0] = (s[0] == 'R' ? 1 : -1);
    suf[s.size() - 1] = (s.back() == 'R' ? -1 : 1);

    for(int i = 1;i < s.size();i++){
        if(s[i] == s[i - 1]){
            pre[i] = pre[i - 1] + (s[i] == 'R' ? 1 : -1);
        }
        else pre[i] = (s[i] == 'R' ? 1 : -1);
    }

    for(int i = s.size() - 2;i >= 0;i--){
        if(s[i] == s[i + 1]){
            suf[i] = suf[i + 1] + (s[i] == 'R' ? -1 : 1);
        }
        else suf[i] = (s[i] == 'R' ? -1 : 1);
    }

    for(int i = 0;i <= s.size();i++){
        if(!i){
            ll l = max(1, 1 + suf[i]), r = min(n, n + suf[i]);
            arr[l]++; arr[r + 1]--;
        }
        else if(i != s.size()){
            ll l = 1 + max(pre[i - 1], 0) + max(suf[i], 0), r = n + min(pre[i - 1], 0) + min(suf[i], 0);
            arr[l]++; arr[r + 1]--;
        }
        else{
            ll l = max(1, 1 + pre[i - 1]), r = min(n, n + pre[i - 1]);
            arr[l]++; arr[r + 1]--;
        }
    }

    ll sum = 0;
    for(int i = 1;i <= n;i++){
        sum += arr[i];
        cout << sum << " ";
    }
    cout << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

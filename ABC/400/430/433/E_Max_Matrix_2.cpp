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
ll a[MAX], b[MAX], c[MAX];
ll y[MAX], x[MAX], result[MAX];
ll my[MAX], mx[MAX];
bool use[MAX], flag;
priority_queue <ll> pq;
priority_queue <pll> num;

ll idx(ll cy, ll cx){
    cy--; cx--;
    return cy * m + cx;
}

void run(){
    cin >> n >> m; flag = 1;
    for(int i = 1;i <= n * m;i++){
        c[i] = use[i] = 0;
        y[i] = x[i] = -1;
        my[i] = mx[i] = -1;
        result[i - 1] = -1;
    }

    while(!pq.empty()) pq.pop();
    while(!num.empty()) num.pop();
    for(int i = 1;i <= n * m;i++) pq.push(i);

    for(int i = 1;i <= n;i++) cin >> a[i], c[a[i]] |= 1, y[a[i]] = i; 
    for(int i = 1;i <= m;i++) cin >> b[i], c[b[i]] |= 2, x[b[i]] = i; 

    for(int i = 1;i <= n * m;i++){
        if(c[i] != 3) continue;
        ll cy = y[i], cx = x[i];
        result[idx(cy, cx)] = i;
        use[i] = 1;
    }

    for(int i = n * m;i >= 1;i--){
        if(c[i] != 1 && c[i] != 2) continue;

        ll mx = -1, now = -1;
        if(y[i] != -1){
            for(int j = 1;j <= m;j++){
                if(b[j] <= mx) continue;
                mx = b[j]; now = j; 
            }
        }
        else{
            for(int j = 1;j <= n;j++){
                if(a[j] <= mx) continue;
                mx = a[j]; now = j; 
            }

        }

        if(now == -1){
            flag = 0; break;
        }

        use[i] = 1;
        result[y[i] != -1 ? idx(y[i], now) : idx(now, x[i])] = i;
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(result[idx(i, j)] != -1) continue;
            num.push({min(a[i], b[j]), idx(i, j)});
        }
    }

    while(!num.empty()){
        auto [cur, now] = num.top(); num.pop();
        while(!pq.empty()){
            auto v = pq.top(); pq.pop();
            if(use[v] || v > cur) continue;
            use[v] = 1; result[now] = v; break;
        }
    }

    for(int i = 0;i < n * m;i++) flag &= (result[i] != -1);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            mx[j] = max(mx[j], result[(idx(i, j))]);
            my[i] = max(my[i], result[(idx(i, j))]);
        }
    }

    for(int i = 1;i <= n;i++) flag &= (a[i] == my[i]);
    for(int i = 1;i <= m;i++) flag &= (b[i] == mx[i]);

    if(!flag){
        cout << "No\n"; return;
    }

    cout << "Yes\n";
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) cout << result[idx(i, j)] << " ";
        cout << "\n";
    }
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

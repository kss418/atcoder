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
vector <ll> adj[MAX], arr;
ll p[MAX], l, r, seq, sz[MAX], result, top[MAX];
bool v[MAX];

void mktree(int cur, int pre = -1){
    sz[cur] = 1;
    for(auto& nxt : adj[cur]){
        if(pre == nxt) continue;
        p[nxt] = cur;
        if(!cur) top[nxt] = nxt;
        else top[nxt] = top[cur];
        mktree(nxt, cur);
        sz[cur] += sz[nxt];
    }
}

void run(){
    cin >> n;
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    bool flag = 1;
    mktree(0); v[0] = 1;
    for(int i = 1;i <= n;i++){
        ll now = i - 1, tmp = i - 1;
        if(!v[tmp]) while(1){
            if(tmp == l){
                v[tmp] = 1;
                l = now; break;
            }
            else if(tmp == r){
                v[tmp] = 1;
                r = now; break;
            }
            else if(v[tmp]){
                flag = 0;
                break;
            }
            else{
                v[tmp] = 1;
                tmp = p[tmp];
            }
        }

        if(!flag) break;
        ll cnt = 0;
        if(!l && !r){
            ll sum = 0;
            for(auto& nxt : adj[0]){
                cnt += (sum + 1) * sz[nxt];
                sum += sz[nxt];
            }
            cnt++;
        }
        else if(!l) cnt = sz[r] * (sz[0] - sz[top[r]]);
        else if(!r) cnt = sz[l] * (sz[0] - sz[top[l]]);
        else cnt = sz[l] * sz[r];

        arr.push_back(cnt);
    }   

    arr.push_back(0);
    for(int i = 0;i + 1 < arr.size();i++){
        result += (arr[i] - arr[i + 1]) * (i + 1);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

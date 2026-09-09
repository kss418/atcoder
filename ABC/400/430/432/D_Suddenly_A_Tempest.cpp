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
struct node{
    ll x1, y1, x2, y2;
    bool operator < (const node& ot) const{
        if(ot.x1 != x1) return x1 < ot.x1;
        if(ot.y1 != y1) return y1 < ot.y1;
        if(ot.x2 != x2) return x2 < ot.x2;
        return y2 < ot.y2;
    }
}; set <node> arr;
vector <pair<node, int>> vec;

void op(char c, int a, int b){
    vector <node> tmp;
    if(c == 'X'){
        for(auto it = arr.begin();it != arr.end();){
            auto& [x1, y1, x2, y2] = *it;
            if(x1 < a && x2 > a){
                tmp.push_back({x1, y1 - b, a, y2 - b});
                tmp.push_back({a, y1 + b, x2, y2 + b});
            }
            else if(x2 <= a){
                tmp.push_back({x1, y1 - b, x2, y2 - b});
            }
            else{
                tmp.push_back({x1, y1 + b, x2, y2 + b});
            }

            it = arr.erase(it);
        }

        for(auto& i : tmp) arr.insert(i);
    }
    else{
        for(auto it = arr.begin();it != arr.end();){
            auto& [x1, y1, x2, y2] = *it;
            if(y1 < a && y2 > a){
                tmp.push_back({x1 - b, y1, x2 - b, a});
                tmp.push_back({x1 + b, a, x2 + b, y2});
            }
            else if(y2 <= a){
                tmp.push_back({x1 - b, y1, x2 - b, y2});
            }
            else{
                tmp.push_back({x1 + b, y1, x2 + b, y2});
            }

            it = arr.erase(it);
        }

        for(auto& i : tmp) arr.insert(i);
    }
}

vector <int> adj[1 << 15];
vector <ll> result;
ll sz[1 << 15];
bool v[1 << 15];
map <ll, set<tll>> mp;

ll dfs(ll cur){
    if(v[cur]) return 0;
    ll ret = sz[cur]; v[cur] = 1;
    for(auto& nxt : adj[cur]) ret += dfs(nxt);
    return ret;
}

void run(){
    cin >> n >> m >> k;
    arr.insert({0, 0, m, k});

    for(int i = 1;i <= n;i++){
        char c; int a, b;
        cin >> c >> a >> b;
        op(c, a, b);
    }
    
    for(auto& i : arr) vec.push_back({i, -1});
    for(int i = 0;i < vec.size();i++){
        auto [x1, y1, x2, y2] = vec[i].x;
        vec[i].y = i;
        sz[i] = (x2 - x1) * (y2 - y1);

        auto& now = mp[x1];
        for(auto it = now.begin();it != now.end();++it){
            auto& [cy1, cy2, pre] = *it;
            if(cy1 >= y2) break;
            if(cy2 <= y1) continue;
            adj[pre].push_back(i);
            adj[i].push_back(pre);
        }

        mp[x2].insert({y1, y2, i});
        vec[i].x = {y1, x1, y2, x2};
    }

    sort(all(vec)); mp.clear();
    for(int i = 0;i < vec.size();i++){
        auto& [x1, y1, x2, y2] = vec[i].x;
        int idx = vec[i].y;

        auto& now = mp[x1];
        for(auto it = now.begin();it != now.end();++it){
            auto& [cy1, cy2, pre] = *it;
            if(cy1 >= y2) break;
            if(cy2 <= y1) continue;
            adj[pre].push_back(idx);
            adj[idx].push_back(pre);
        }

        mp[x2].insert({y1, y2, idx});
    }

    for(int i = 0;i < vec.size();i++){
        if(v[i]) continue;
        result.push_back(dfs(i));
    }

    sort(all(result));
    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

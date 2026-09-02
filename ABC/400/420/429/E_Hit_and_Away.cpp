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

vector <int> adj[MAX];
struct node{
    int d, v;
    bool operator > (const node& ot) const{
        return d > ot.d;
    }

    bool operator < (const node& ot) const{
        return d < ot.d;
    }

    bool operator <= (const node& ot) const{
        return d <= ot.d;
    }
};

using pni = pair<node, int>;
priority_queue <pni, vector<pni>, greater<pni>> pq;
pair <node, node> dist[MAX];
void run(){
    cin >> n >> m;
    while(m--){
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for(int i = 1;i <= n;i++) dist[i] = {{0x3f3f3f3f, i}, {0x3f3f3f3f, i}};
    
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(s[i] == 'D') continue;
        pq.push({{0, i + 1}, i + 1});
    }

    while(!pq.empty()){
        auto [cn, cur] = pq.top(); pq.pop();
        if(cn.d >= dist[cur].y.d) continue;

        if(cn.v == dist[cur].x.v){
            if(dist[cur].x <= cn) continue;
            dist[cur].x = cn;
        }
        else dist[cur].y = cn;
        
        if(dist[cur].x > dist[cur].y) swap(dist[cur].x, dist[cur].y);
        
        for(auto& nxt : adj[cur]){
            node nn = {cn.d + 1, cn.v};
            pq.push({nn, nxt});
        }
    }

    for(int i = 0;i < s.size();i++){
        if(s[i] == 'S') continue;
        cout << dist[i + 1].x.d + dist[i + 1].y.d << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

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
constexpr ll MAX = 12; // SET MAX SIZE
constexpr ll MOD = 998244353;

bool outrange(int cy, int cx){
    return cy < 0 || cx < 0 || cy >= n || cx >= m;
}

vector <string> st;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
bool move(vector <string>& st, vector <string>& ret, int dir){
    ret = st;
    int ty = -1, tx = -1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int ny = i - dx[dir], nx = j - dy[dir];
            if(st[i][j] == 'T'){ ty = i, tx = j; }
            if(outrange(ny, nx)) ret[i][j] = '.';
            else ret[i][j] = (st[ny][nx] == '#' ? '#' : '.');
        }
    }

    if(ret[ty][tx] == '#') return 1;
    ret[ty][tx] = 'T';
    return 0;
}

deque <vector<string>> q;
unordered_map <string, int> mp;

string get_key(vector <string>& st){
    string ret;
    for(auto& s : st) ret += s;
    return ret;
}

bool chk(vector <string>& st){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++) if(st[i][j] == '#') return 0;
    }
    return 1;
}

int result = -1;
void run(){
    cin >> n >> m; st.resize(n);
    for(int i = 0;i < n;i++) cin >> st[i];
    q.push_back(st); mp[get_key(st)] = 0;

    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        string ck = get_key(cur);
        if(chk(cur)){
            result = mp[ck];
            break;
        }

        for(int i = 0;i < 4;i++){
            vector <string> nxt;
            bool flag = move(cur, nxt, i);
            if(flag) continue;

            string nk = get_key(nxt);
            if(mp.count(nk)) continue;
            mp[nk] = mp[ck] + 1;
            q.push_back(nxt);
        }
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
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
string a, b;
bool fa[26], fb[26];

bool chk1(const string& st){
    for(auto& i : st){
        if(!fa[i - 'a']) return 0;
    }
    return 1;
}

bool chk2(const string& st){
    for(auto& i : st){
        if(!fb[i - 'a']) return 0;
    }
    return 1;
}

void run(){
    cin >> n >> m >> a >> b >> k;
    for(auto& i : a) fa[i - 'a'] = 1;
    for(auto& i : b) fb[i - 'a'] = 1;

    while(k--){
        string s; cin >> s;
        bool x = chk1(s) ^ chk2(s);
        if(x){
            cout << (chk1(s) ? "Takahashi" : "Aoki") << "\n";
        }
        else cout << "Unknown" << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;

string a, b;
ll len[MAX], sum[100][26];
int sa[10101][26], sb[10101][26];
ll dnc(int cur, ll l, ll r, char c){
    if(l > r || cur <= 0) return 0;
    if(cur == 1) return sa[r][c - 'a'] - sa[l - 1][c - 'a'];
    if(cur == 2) return sb[r][c - 'a'] - sb[l - 1][c - 'a'];

    if(l == 1 && r == len[cur]) return sum[cur][c - 'a'];

    if(r <= len[cur - 1]) return dnc(cur - 1, l, r, c);
    else if(l > len[cur - 1]) return dnc(cur - 2, l - len[cur - 1], r - len[cur - 1], c);
    return dnc(cur - 1, l, len[cur - 1], c) + dnc(cur - 2, 1, r - len[cur - 1], c);
}

int mx;
void run(){
    cin >> a >> b >> m;
    len[1] = a.size(); len[2] = b.size();
    for(int i = 3;i < 100;i++){
        i128 nxt = len[i - 1] + len[i - 2];
        if(nxt > INF) break;
        len[i] = nxt; mx = i;
    }

    for(int i = 1;i <= a.size();i++){
        for(int j = 0;j < 26;j++) sa[i][j] = sa[i - 1][j] + (a[i - 1] - 'a' == j);
    }

    for(int i = 1;i <= b.size();i++){
        for(int j = 0;j < 26;j++) sb[i][j] = sb[i - 1][j] + (b[i - 1] - 'a' == j);
    }

    for(int i = 0;i < 26;i++) sum[3][i] = sa[a.size()][i] + sb[b.size()][i];
    for(int i = 0;i < 26;i++) sum[4][i] = sum[3][i] + sb[b.size()][i];
    for(int i = 5;i <= mx;i++){
        for(int j = 0;j < 26;j++) sum[i][j] = sum[i - 1][j] + sum[i - 2][j];
    }


    while(m--){
        ll l, r; char c; cin >> l >> r >> c;
        cout << dnc(mx, l, r, c) << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}
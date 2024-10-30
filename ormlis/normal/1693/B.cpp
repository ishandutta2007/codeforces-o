#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 2e5 + 20;
const int LG = 30;

vi g[maxN];
int dp[maxN];
int l[maxN], r[maxN];
int ans = 0;

void dfs(int v) {
    ll s = 0;
    for (auto &u : g[v]) {
        dfs(u);
        s += dp[u];
    }
    s = min(s, 1ll * r[v]);
    if (s >= l[v]) {
        dp[v] = s;
    } else {
        ans++;
        dp[v] = r[v];
    }
}

void solve() {
    int n;
    cin >> n;
    ans = 0;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
    dfs(1);
    cout << ans << '\n';
    for(int i = 1; i <= n; ++i) g[i].clear();
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
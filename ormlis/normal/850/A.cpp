#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5 + 30;
const int LG = 20;

void solve() {
    int n; cin >> n;
    vector<ar<int, 5>> a(n);
    rep(i, n) rep(j, 5) cin >> a[i][j];
    vi ans;
    rep(i, n) {
        bool good = true;
        rep(j, n) {
            if (j == i) continue;
            rep(e, j) {
                if (e == i) continue;
                ll val = 0;
                rep(t, 5) val += 1ll * (a[j][t] - a[i][t]) * (a[e][t] - a[i][t]);
                if (val > 0) {
                    good = false;
                    break;
                }
            }
            if (!good) break;
        }
        if (good) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
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
const int maxN = 2e7 + 30;
const int LG = 100;
const int md = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;
    vi dp2(n + 1, -1);
    for (int i = 0; i <= n; ++i) {
        vi cnt(n);
        int mx = 0;
        int cnt_all = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (mx * 2 <= cnt_all && (cnt_all % 2 == 0) && (i == n || a[j] == a[i]) &&
                dp2[j] != -1) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
            cnt_all++;
            cnt[a[j]]++;
            mx = max(mx, cnt[a[j]]);
        }
        if (mx * 2 <= cnt_all && cnt_all % 2 == 0) {
            dp2[i] = max(dp2[i], 1);
        }
    }
    cout << dp2[n] - 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
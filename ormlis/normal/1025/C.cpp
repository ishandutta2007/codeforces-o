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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
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

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pref(n + 1), suf(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1];
        if (pref[i] == i - 1 && (i == 1 || s[i - 1] != s[i - 2])) {
            pref[i]++;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1];
        if (suf[i] == n - i - 1 && (i == n - 1 || s[i] != s[i + 1])) {
            suf[i]++;
        }
    }
    int ans = 0;
    {
        int len = 0;
        rep(i, n) {
            if (i == 0 || s[i] == s[i - 1]) len = 0;
            len++;
            ans = max(ans, len);
        }
    }
    if (s[0] != s[n - 1]) {
        for (int i = 1; i < n; ++i) {
            ans = max(ans, pref[i] + suf[i]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
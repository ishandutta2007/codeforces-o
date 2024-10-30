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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5;
const int LG = 30;

void solve() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    if (abs(a - b) > 1) {
        cout << "-1\n";
        return;
    }
    if (a + b > n - 2) {
        cout << "-1\n";
        return;
    }
    if (a == b) {
        int t = 1;
        cout << t++ << ' ';
        for (int i = 1; i <= a; ++i) {
            cout << t + 1 << ' ';
            cout << t << ' ';
            t += 2;
        }
        while (t <= n) cout << t++ << ' ';
        cout << '\n';
        return;
    }
    if (a == b + 1) {
        int t = (n - a * 2 - 1) + 1;
        cout << t++ << ' ';
        for (int i = 1; i <= a; ++i) {
            cout << t + 1 << ' ';
            cout << t << ' ';
            t += 2;
        }
        int w = n - a * 2 - 1;
        while (w >= 1) cout << w-- << ' ';
        cout << '\n';
        return;
    }
    int t = (n - b * 2 - 1) + 1;
    cout << n + 1 - (t++) << ' ';
    for (int i = 1; i <= b; ++i) {
        cout << n + 1 - (t + 1) << ' ';
        cout << n + 1 - t << ' ';
        t += 2;
    }
    int w = n - b * 2 - 1;
    while (w >= 1) cout << (n + 1) - (w--) << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}
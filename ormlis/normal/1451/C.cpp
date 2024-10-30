#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

// using namespace __gnu_pbds;
using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


void solve() {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    vector<int> cnta(27), cntb(27);
    for(auto &c: a) cnta[c-'a']++;
    for(auto &c: b) cntb[c-'a']++;
    range(i, 26) {
        if (cnta[i] < cntb[i]) {
            cout << "NO\n";
            return;
        }
        int need = cnta[i] - cntb[i];
        if (need % k != 0) {
            cout << "NO\n";
            return;
        }
        cnta[i + 1] += need;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
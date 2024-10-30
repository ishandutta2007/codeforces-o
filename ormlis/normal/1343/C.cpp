#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    ll ans = 0;
    vector<int> a(n);
    range(i, n) cin >> a[i];

    auto sign = [&] (int a) {
        return a < 0;
    };

    for(int i = 0, j = 0; i < n; i = j) {
        int cur = a[i];
        while( j < n && sign(a[i]) == sign(a[j])) {
            cur = max(cur, a[j]);
            j++;
        }
        ans += cur;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
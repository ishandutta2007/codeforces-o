#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };


void solve() {
    int n; cin >> n;
    int cnt0 = 0, cnt1 = 0;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    range(i, n) {
        if (a[i] == 0) cnt0++;
        else cnt1++;
    }
    if (cnt0 >= cnt1) {
        cout << n / 2 << "\n";
        range(i, n / 2) {
            cout << "0 ";
        }
        cout << "\n";
        return;
    }
    cout << n / 2 + (n / 2) % 2 << "\n";
        range(i, n / 2 + (n / 2) % 2) cout << "1 ";
        cout << "\n";
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}
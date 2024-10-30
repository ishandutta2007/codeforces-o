#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

string rev(string s) {
    reverse(s);
    return s;
}

signed main() {
    FAST; FIXED; RANDOM;
    string s;
    cin >> s;
    int n = sz(s);
    vector<string> dp[2];
    vector<vector<ll>> p(2, vector<ll>(n));
    dp[0].resize(n);
    dp[1].resize(n);
    p[0][0] = 0;
    p[1][0] = 0;
    dp[0][0] = s[0];
    dp[1][0] = s[0];
    for (int i = 1; i < n; ++i) {
        p[0][i] = 0;
        p[1][i] = 1;
        dp[0][i] = dp[0][i - 1] + s[i];
        dp[1][i] = dp[1][i - 1] + s[i];
        if (rev(dp[1][i - 1] + s[i]) < dp[0][i]) {
            p[0][i] = 1;
            dp[0][i] = rev(dp[1][i - 1] + s[i]);
        }
        if (rev(dp[0][i - 1] + s[i]) > dp[1][i]) {
            p[1][i] = 0;
            dp[1][i] = rev(dp[0][i - 1] + s[i]);
        }
    }
    vector<ll> ans(n);
    int curr = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = p[curr][i] ^ curr;
        curr = p[curr][i];
    }
    for (auto i : ans) cout << i << ' ';
    return 0;
}
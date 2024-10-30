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
#define checkmin(x, y) if (x > y) x = y
#define checkmax(x, y) if (x < y) x = y
#define sort(a) sort(all(a))
#define rsort(a) sort(rall(a))
#define reverse(a) reverse(all(a))
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)]);

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    for (int i = 0; i < n && (i == 0 || arr[i] > arr[i - 1]); ++i) 
        for (int j = i; j < n && arr[j] == arr[i]; ++j) {
            bool flag = true;
            for (int k = j + 1; k < n && flag; ++k)
                if (arr[k] >= arr[k - 1]) flag = false;
            if (flag) {
                cout << "YES";
                return 0;
            }
        }
    cout << "NO";
    return 0;
}
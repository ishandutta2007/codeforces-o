#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll

#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

int main() {
    FAST;
    int n, k, m;
    cin >> n >> k >> m;
    vector<string> arr(n);
    for (auto &i : arr) cin >> i;
    vector<int> cost(n);
    for (auto &i : cost) cin >> i;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        vector<int> inp(x);
        int minn = mod;
        for (auto &j : inp) cin >> j, --j, minn = min(minn, cost[j]);
        for (auto j : inp) cost[j] = minn;
    }
    hashmap<string, int> mymap;
    for (int i = 0; i < n; ++i)
        if (mymap.count(arr[i])) mymap[arr[i]] = min(mymap[arr[i]], cost[i]);
        else mymap[arr[i]] = cost[i];
    string temp;
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        ans += mymap[temp];
    }
    cout << ans;    
    return 0;
}
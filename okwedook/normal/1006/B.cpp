#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 998244353
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<class T1, class T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<class T1, class T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<class T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<class T1> inline void rsort(T1 &arr) { sort(arr.rbegin(), arr.rend()); }
template<class T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
template<class T1> inline void shuffle(T1 &arr) { 
    for (int i = -int(arr.size()); i < arr.size(); ++i) {
        int f = ((rand() << 16) + rand()) % arr.size(), s = ((rand() << 16) + rand()) % arr.size();
        swap(arr[f], arr[s]);
    }
}
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

signed main() {
	FAST;
	ll n, k;
	cin >> n >> k;
	vector<pll> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].f; arr[i].s = i;
	}
	sort(arr);
	reverse(arr);
	vector<bool> used(n);
	ll summ = 0;
	for (int i = 0; i < k; ++i) used[arr[i].s] = true, summ += arr[i].f;
	cout << summ << '\n';
	ll curr = 0;
	vector<ll> ans;
	ll last = 0;
	for (int i = 0; i < n; ++i)
		if (used[i]) {
			ans.pb(i - curr + 1);
			curr = i + 1;
			last = curr;
		}
	ans[ans.size() - 1] += n - last;
	for (auto i : ans) cout << i << ' ';
	return 0; 
}
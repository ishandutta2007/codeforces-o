#pragma GCC optimize("O3","unroll-loops")
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
#define eps 1e-9
#define mod 1000000007
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
    for (int i = -int(arr.size()); i < int(arr.size()); ++i)
        swap(arr[rand() % arr.size()], arr[rand() % arr.size()]);
}
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;


signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<ll> arr(n), brr(n);
    for (auto &i : arr) cin >> i;
    for (auto &i : brr) cin >> i;
    ll summ1 = 0, summ2 = 0;
	for (auto &i : arr) summ1 += i;
	for (auto &i : brr) summ2 += i;
	if (summ2 <= summ1) cout << "Yes";
	else cout << "No";
    return 0; 
}
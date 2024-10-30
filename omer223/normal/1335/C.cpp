#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define has(set, x) set.find(x) != set.end()
#define nohas(set, x) set.find(x) == set.end()
#define inc(mpp, x) {if(has(mpp, x)) mpp[x]++; else mpp.insert(mp(x,1));}
#define decc(mpp, x) {if(has(mpp, x)) {if(mpp[x] > 1) mpp[x]--; else mpp.erase(x);}}
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define um unordered_map
#define us unordered_set
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }

ll arr[200005];


int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll t, n, a, b, mxSame, diff;
	um<ll, ll> cnt;
	cin >> t;
	while (t--) {
		mxSame = 1; diff = 0;
		cnt.clear();
		cin >> n;
		FOR(i, n) {
			cin >> arr[i];
			if (cnt.find(arr[i]) == cnt.end()) { cnt.insert(mp(arr[i], 1)); diff++; }
			else { cnt[arr[i]]++; mxSame = max(mxSame, cnt[arr[i]]); }
		}
		if (n < 2) cout << 0 << endl;
		else if (mxSame == diff) cout << max(diff - 1, 1LL) << endl;
		else if (mxSame > diff) cout << max(diff, 1LL) << endl;
		else cout << max(mxSame, 1LL) << endl;
	}

	return 0;
}
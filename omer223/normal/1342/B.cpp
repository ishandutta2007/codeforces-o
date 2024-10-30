#define MOD 1000000007
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
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
#include <chrono>
#include <bitset>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};



int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	ll n, m, a, b, c, d, x, y, z, t;
	string s;
	int status = -1;
	cin >> t;
	while (t--) {
		cin >> s;
		status = -1;
		bool flag = true;
		for (char c : s) {
			if (c == '0' && status == 1) flag = false;
			else if (c == '0') status = 0;
			else if (c == '1' && status == 0) flag = false;
			else if (c == '1') status = 1;
		}
		if (flag) {cout << s << endl; continue;
		}
		string res = ""; 
		int len = s.length();
		foru(i, 0, len) {
			if (i == 0) res.pb(s[i]);
			else if (abs(s[i] - s[i - 1]) == 1) res.pb(s[i]);
			else if (s[i] == '0') { res.pb('1'); res.pb('0'); }
			else { res.pb('0'); res.pb('1'); }
		}
		cout << res << endl;
	}
	
	return 0;
}
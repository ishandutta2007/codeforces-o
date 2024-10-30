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
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
#include <numeric>
using namespace std;
const int INF = 1 << 29;
typedef long long ll;
typedef unsigned long long ull;
inline int two(int n) { return 1 << n; }
ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }
ll modpow(ll a, ll b) { ll res = 1; a %= MOD; for (; b; b >>= 1) { if (b & 1)res = res * a%MOD; a = a * a%MOD; }return res; }

const int sz = 2e3 + 5;
ll dp[sz][sz][2], n;//needmore, debt, lightroot
int main() {
	fast;
	ifstream in("input.txt");
	ofstream out("output.txt");
	cin >> n;
	foru(i, 1, 2*n + 1) {
		foru(debt, 0, i + 1) {
			if ((i + debt) & 1)continue;//check
			if (i == 1) {
				dp[i][debt][1] = 1;
			}
			else {
				if (!debt) {
					dp[i][debt][1] = dp[i - 1][debt + 1][0] + 1;
					dp[i][debt][0] = dp[i - 1][debt + 1][1];
				}
				else if (debt == i) {
					dp[i][debt][1] = dp[i - 1][debt - 1][0] + 1;
					dp[i][debt][0] = dp[i - 1][debt - 1][1];
				}
				else {
					dp[i][debt][0] = dp[i - 1][debt - 1][1] + dp[i - 1][debt + 1][1];
					dp[i][debt][1] = max(dp[i - 1][debt - 1][0] + dp[i - 1][debt + 1][1] + 1, dp[i - 1][debt - 1][1] + dp[i - 1][debt + 1][0] + 1);
				}
			}
			dp[i][debt][1] %= MOD;
			dp[i][debt][0] %= MOD;
		}
	}
	cout << dp[2*n][0][1] << endl;
	return 0;
}
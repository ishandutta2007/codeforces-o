#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;



void Solve() {
	cin >> N;
	map<int, int>mp;
	int num = 0;
	for (int i = 0; i < N; i++) {
		cin >> K;
		mp[K]++;
		num = max(num, mp[K]);
	}
	int ans = 0;
	while (num < N) {
		int l = num;
		ans++;
		for (int i = 0; i < l; i++) {
			if (num < N) {
				ans++;
				num++;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}
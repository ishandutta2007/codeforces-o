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

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long  double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<long long int>v(N);
	for (auto &i : v) {
		cin >> i;
	}
	if (N > M) {
		cout << 0 << endl;
		return 0;
	}
	long long int ans = 1;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			ans *= abs(v[i] - v[j]);
			ans %= M;
		}
	}
	cout << ans << endl;
}
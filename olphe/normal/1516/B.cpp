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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	for (int i = 1; i < N; i++) {
		v[i] ^= v[i - 1];
	}
	if (v.back() == 0) {
		cout << "YES\n";
		return;
	}
	int flag = 0;
	for (auto i : v) {
		if (flag==0&&i == v.back()) {
			flag = 1;
		}
		if (flag == 1) {
			if (i == 0) {
				flag = 2;
			}
		}
	}
	if (flag == 2)cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}
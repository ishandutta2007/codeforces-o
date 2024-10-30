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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<long long int>v(N);
		for (auto &i : v)cin >> i;
		vector<long long int>w(N);
		for (int i = 1; i < N; i++) {
			if (v[i] > v[i - 1]) {
				w[i] += v[i] - v[i - 1];
			}
		}
		for (int i = 0; i < N - 1; i++) {
			if (v[i] > v[i + 1]) {
				w[0] += v[i] - v[i + 1];
				w[i + 1] -= v[i] - v[i + 1];
			}
		}
		for (int i = 1; i < N; i++) {
			w[i] += w[i - 1];
		}
		for (int i = 0; i < N; i++) {
			v[i] -= w[i];
		}
		L = *min_element(v.begin(), v.end());
		R = *max_element(v.begin(), v.end());
		if (L == R && L >= 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}
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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<int>v(K + 1);
	for (int i = 0; i < N; i++) {
		cin >> M;
		v[M]++;
	}
	int ans = 0;
	int used = 0;
	int amari = 0;
	for (int i = 1; i <= K; i++) {
		ans += v[i] / 2 * 2;
		used += v[i] / 2;
		amari += v[i] & 1;
	}
	cout << ans + min((long long)amari, (N + 1) / 2 - used) << endl;
}
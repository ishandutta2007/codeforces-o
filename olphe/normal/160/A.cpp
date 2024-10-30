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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < N; i++) {
		if (accumulate(v.begin(), v.end(), 0) < 2 * accumulate(v.begin(), v.begin() + i + 1, 0)) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	return 0;
}
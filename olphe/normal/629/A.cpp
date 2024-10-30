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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<string>s(N);
	for (auto &i : s)cin >> i;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			cnt += s[i][j] == 'C';
		}
		M += cnt * (cnt - 1) / 2;
		cnt = 0;
		for (int j = 0; j < N; j++) {
			cnt += s[j][i] == 'C';
		}
		M += cnt * (cnt - 1) / 2;
	}
	cout << M << endl;
	return 0;
}
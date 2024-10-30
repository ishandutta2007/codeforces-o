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

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string s;
	cin >> s;
	if (N == 1) {
		cout << "YES\n";
		return 0;
	}
	map<int, int>m;
	for (auto i : s) {
		m[i]++;
	}
	for (auto i : m) {
		if (i.second >= 2) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
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
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string s;
	cin >> s;
	vector<int>v(10);
	for (auto i : s) {
		if (i == 'L') {
			for (int i = 0; i < 10; i++) {
				if (!v[i]) {
					v[i] = 1;
					break;
				}
			}
		}
		else if (i == 'R') {
			for (int i = 9; i >= 0; i--) {
				if (!v[i]) {
					v[i] = 1;
					break;
				}
			}
		}
		else {
			int cn = i - '0';
			v[cn] = 0;
		}
	}
	for (auto i : v)cout << i;
	cout << endl;
}
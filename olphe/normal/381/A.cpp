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
	list<int>v;
	for (int i = 0; i < N; i++) {
		cin >> M;
		v.push_back(M);
	}
	for (int i = 0; i < N; i++) {
		K = max(v.front(), v.back());
		if (v.front() > v.back()) v.pop_front();
		else v.pop_back();
		if (i % 2)R += K;
		else L += K;
	}
	cout << L << " " << R << endl;
	return 0;
}
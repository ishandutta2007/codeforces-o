#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 2100
#define MOD 1000000007 //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	int n, m;
	char a[N];

	cin >> n;
	rep(i, n) {
		rep(j, N)a[j] = 0;
        cin>>m;
		cin >> a;
		sort(a, a + m);
		cout << a << endl;
	}
	return 0;
}
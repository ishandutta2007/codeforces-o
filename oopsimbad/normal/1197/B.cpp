#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	vi v; int l, r;
	l = r = 0;
	F0R(i, n) {
		int a; cin >> a; v.pb(a);
		if(v[l] < a) l = r = i;
	}
	l--; r++;
	FORd(i, 1, n) {
		if(l != -1 && v[l] == i) l--;
		else if(r != n && v[r] == i) r++;
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
///
	return 0;
}
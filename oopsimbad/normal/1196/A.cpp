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
	while(n--) {
		ll a, b, c; cin >> a >> b >> c;
		vll v; v.pb(a); v.pb(b); v.pb(c);
		sort(v.begin(), v.end());
		a = v[0];
		b = v[1];
		c = v[2];
		ll d = min(b-a, c);
		a += d;
		cout << min(a,b) + (c-d)/2 << endl;
	}
///
	cin >> n;
	return 0;
}
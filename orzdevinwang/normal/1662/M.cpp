#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;

const int N = 1e6 + 7; 

int n, m, r, w;
void Main() {
	cin >> n >> m;
	r = w = 0;
	L(i, 1, m) {
		int R, W;
		cin >> R >> W;
		r = max(r, R);
		w = max(w, W);
	}
	if(r + w > n) cout << "IMPOSSIBLE\n";
	else {
		w = n - r;
		L(i, 1, r) cout << "R";
		L(i, 1, w) cout << "W";
		cout << '\n';
	}
	
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0; 
}
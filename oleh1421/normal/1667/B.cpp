#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef pair<int, int> Pii;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

template<int mod, int primitive_root>
class NTT {
public:
	int get_mod() const { return mod; }
	void _ntt(vector<ll>& a, int sign) {
		const int n = sz(a);
		assert((n ^ (n&-n)) == 0); //n = 2^k

		const int g = 3; //g is primitive root of mod
		int h = (int)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
		if (sign == -1) h = (int)mod_inv(h, mod); //h = h^-1 % mod

		//bit reverse
		int i = 0;
		for (int j = 1; j < n - 1; ++j) {
			for (int k = n >> 1; k >(i ^= k); k >>= 1);
			if (j < i) swap(a[i], a[j]);
		}

		for (int m = 1; m < n; m *= 2) {
			const int m2 = 2 * m;
			const ll base = mod_pow(h, n / m2, mod);
			ll w = 1;
			FOR(x, m) {
				for (int s = x; s < n; s += m2) {
					ll u = a[s];
					ll d = a[s + m] * w % mod;
					a[s] = u + d;
					if (a[s] >= mod) a[s] -= mod;
					a[s + m] = u - d;
					if (a[s + m] < 0) a[s + m] += mod;
				}
				w = w * base % mod;
			}
		}

		for (auto& x : a) if (x < 0) x += mod;
	}
	void ntt(vector<ll>& input) {
		_ntt(input, 1);
	}
	void intt(vector<ll>& input) {
		_ntt(input, -1);
		const int n_inv = mod_inv(sz(input), mod);
		for (auto& x : input) x = x * n_inv % mod;
	}

	vector<ll> convolution(const vector<ll>& a, const vector<ll>& b){
		int ntt_size = 1;
		while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;

		vector<ll> _a = a, _b = b;
		_a.resize(ntt_size); _b.resize(ntt_size);

		ntt(_a);
		ntt(_b);

		FOR(i, ntt_size){
			(_a[i] *= _b[i]) %= mod;
		}

		intt(_a);
		return _a;
	}
};

ll garner(vector<Pii> mr, int mod){
	mr.emplace_back(mod, 0);

	vector<ll> coffs(sz(mr), 1);
	vector<ll> constants(sz(mr), 0);
	FOR(i, sz(mr) - 1){
		// coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first)
		ll v = (mr[i].second - constants[i]) * mod_inv<ll>(coffs[i], mr[i].first) % mr[i].first;
		if (v < 0) v += mr[i].first;

		for (int j = i + 1; j < sz(mr); j++) {
			(constants[j] += coffs[j] * v) %= mr[j].first;
			(coffs[j] *= mr[i].first) %= mr[j].first;
		}
	}

	return constants[sz(mr) - 1];
}
NTT<998244353,3>NTT_1;
const int N=1000100;
const ll mod=998244353;
const ll mod1=mod*mod;
const int K=18;
const ll inf=1000000000000000001;
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2);
}
ll pref[N];
ll dp[N];
ll mn[N];
ll t[N];
void upd(int n,int pos,ll x){
    for (;pos<=n;pos|=pos+1) t[pos]=max(t[pos],x);
}
ll get(int pos){
    ll mx=-inf;
    for (;pos>=0;pos&=pos+1,pos--) mx=max(mx,t[pos]);
    return mx;

}
void solve(){
    int n;cin>>n;
    pref[0]=mn[0]=0;
    set<ll>st;
    st.insert(0);
    for (int i=1;i<=n;i++){
        ll x;cin>>x;
        pref[i]=pref[i-1]+x;
        st.insert(pref[i]);
    }
    int cnt=0;
    map<ll,ll>mp;
    for (ll x:st){
        mp[x]=++cnt;
    }
    for (int i=0;i<=n;i++) pref[i]=mp[pref[i]];
    for (int i=0;i<=cnt;i++) t[i]=-inf;
    map<ll,ll>best;
    dp[0]=0;
    best[pref[0]]=0;
    upd(cnt,pref[0],0);
    for (int i=1;i<=n;i++){
        dp[i]=dp[i-1]-1;
        if (best.find(pref[i])!=best.end()) dp[i]=max(dp[i],best[pref[i]]);
        dp[i]=max(dp[i],get(pref[i]-1)+i);
        upd(cnt,pref[i],dp[i]-i);
        if (best.find(pref[i])==best.end()) best[pref[i]]=dp[i];
        else best[pref[i]]=max(best[pref[i]],dp[i]);
    }
    cout<<dp[n]<<endl;
    for (int i=0;i<=cnt;i++) t[i]=-inf;




}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
3 10 3 5 1 88


**/
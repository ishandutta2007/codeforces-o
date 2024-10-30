#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <random>
#include <cassert>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)]);

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

vector<pair<char, int>> convert(string s) {
    char past = '0';
    int cnt = 0;
    vector<pair<char, int>> ans;
    for (auto i : s) {
        if (i != past) { 
            if (cnt) ans.pb({past, cnt});
            cnt = 1;
        } else ++cnt;
        past = i;
    }
    ans.pb({past, cnt});
    return ans;
}

void clear(vector<pair<char, int>> &a) {
    vector<pair<char, int>> st;
    for (auto i : a) {
        if (i.s > 0) {
            if (sz(st) && st.back().f == i.f) st[sz(st) - 1].s += i.s;
            else st.pb(i);
        }
    }
    a = st;
}

int sum(const vector<pair<char, int>> &a) {
    int ans = 0;
    for (auto &i : a)
        ans += i.s;
    return ans;
}

struct cmp {
    bool operator()(const vector<pair<char, int>> &a, const vector<pair<char, int>> &b) {
        int sa = sum(a), sb = sum(b);
        if (sa == sb) return a < b;
        return sa > sb;
    }
};

signed main() {
    FAST; FIXED; RANDOM;
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<vector<pair<char, int>>, cmp> st;
    st.insert(convert(s));
    int cnt = 0;
    int ans = 0;
    while (sz(st) && cnt < k) {
        auto f = *st.begin();
        st.erase(f);
        ++cnt;
        ans += n - sum(f);
        if (sz(st) + cnt < k) {
            for (int i = 0; i < sz(f); ++i) {
                auto s = f;
                --s[i].s;
                clear(s);
                st.insert(s);
            }
        }
    }
    if (cnt == k) cout << ans;
    else cout << -1;
    return 0;
}
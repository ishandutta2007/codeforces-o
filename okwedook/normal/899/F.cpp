#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <tuple>
#include <random>
#include <bitset>
#include <queue>

using namespace std;

#define FIXED cout << fixed << setprecision(15)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RANDOM srand(85453532)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 1000000007
#define inf 4000000000000000007ll
#define f first
#define s second
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { 
    if (y < x) return x = y, true;
    return false; 
}
template<class T, class U> inline bool ifmax(T &x, U y) { 
    if (y > x) return x = y, true;
    return false; 
}
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) { 
    for (auto &i : a) stream >> i;
    return stream;
}

const int N = 1e6;
const int LOGN = 20;
int fenv[N];

void add(int r, int x) {
    for (; r < N; r |= r + 1) fenv[r] += x;
}

int get(int r) {
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ans += fenv[r];
    return ans;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}

int lower_bound(int sum) {
    int ans = -1;
    for (int i = LOGN; i >= 0; --i) {
        int ind = ans + (1 << i);
        if (ind >= N || fenv[ind] > sum) continue;
        sum -= fenv[ind];
        ans = ind;
    }
    return ans + 1;
}

set<int> st[256];

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) add(i, 1), st[s[i]].insert(i);
    add(n, 1);
    while (m--) {
        int l, r;
        char c;
        cin >> l >> r >> c;
        --l;
        l = lower_bound(l);
        r = lower_bound(r);
        if (r <= l) continue;
        auto it = st[c].lower_bound(l);
        vector<int> todel;
        while (it != st[c].end() && *it < r) {
            todel.pb(*it);
            ++it;
        }
        for (auto i : todel) add(i, -1), st[c].erase(i);
    }
    vector<bool> used(n);
    for (int i = 0; i < 256; ++i)
        for (auto j : st[i]) used[j] = true;
    for (int i = 0; i < n; ++i) 
        if (used[i]) cout << s[i];
    cout << '\n';
    return 0;
}
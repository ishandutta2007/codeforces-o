#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--) 
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int M = 1.2e7 + 7;
const int mod = 998244353;
const int G = 423141439;
unordered_map<int, int> mp[N];
int n, m, dep[N], ha[N], fa[N], jp[20][N];
int head[N], edge_id;
struct node { int to, next; } e[N << 1];
void add_edge(int u, int v) { ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id; }
int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	R(i, 18, 0) if((dep[x] - dep[y]) >= (1 << i)) x = jp[i][x], y = jp[i][y];
	if(x == y) return x;
	R(i, 18, 0) if(jp[i][x] != jp[i][y]) x = jp[i][x], y = jp[i][y];
	return fa[x];
}
int hd[N];
int sum[M], ch[M][2], tot;
void add(int &id, int L, int R, int wz, int val) {
	if(!id) id = ++tot;
	sum[id] += val;
	if(L == R) return;
	int mid = (L + R) / 2;
	if(wz <= mid) add(ch[id][0], L, mid, wz, val);
	else add(ch[id][1], mid + 1, R, wz, val);
}
int query(int id, int L, int R, int wz) {
	if(!id) return 0;
	if(L == R) return sum[id];
	int mid = (L + R) / 2;
	if(wz <= mid) return query(ch[id][0], L, mid, wz);
	else return query(ch[id][1], mid + 1, R, wz);
}
int merge(int x, int y) {
	if(!x || !y) return x + y;
	int nnode = ++tot;
	sum[nnode] = sum[x] + sum[y];
	ch[nnode][0] = merge(ch[x][0], ch[y][0]);
	ch[nnode][1] = merge(ch[x][1], ch[y][1]);
	return nnode;
}
void dfs(int x) {
	add(hd[x], 1, n, dep[x], 1);
	int las = mp[dep[x]][ha[x]];
	if(las) add(hd[lca(las, x)], 1, n, dep[x], -1);
	mp[dep[x]][ha[x]] = x; 
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		dep[v] = dep[x] + 1, dfs(v);
	}
}
void dfss(int x) {
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		dfss(v), hd[x] = merge(hd[x], hd[v]);
	}
}
char s[N];
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) {
		scanf("%s", s + 1);
		int res = 0, now = 1, len = strlen(s + 1);
		L(i, 1, len) (res += 1ll * now * (s[i] - 'a' + 1) % mod) %= mod, now = 1ll * now * G % mod;
		ha[i] = res;
		scanf("%d", &fa[i]), jp[0][i] = fa[i];
		if(fa[i]) add_edge(fa[i], i);
	}
	L(i, 1, 18) L(j, 1, n) jp[i][j] = jp[i - 1][jp[i - 1][j]];
	L(i, 1, n) if(!dep[i]) dep[i] = 1, dfs(i), dfss(i);
	int q, cnt = 0; scanf("%d", &q);
	while(q--) {
		++cnt;
		int x, y; scanf("%d%d", &x, &y);
		if(dep[x] + y > n) printf("0\n");
		else printf("%d\n", query(hd[x], 1, n, dep[x] + y));
	}
	return 0;
}
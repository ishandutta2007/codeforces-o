#include <bits/stdc++.h>

namespace IO
{
char gc()
{
#ifdef FREAD
	static char buf[1<<21], *P1 = buf, *P2 = buf;
	if(P1 == P2)
	{
		P1 = buf;
		P2 = buf + fread(buf, 1, 1<<21, stdin);
		if(P1 == P2) return EOF;
	}
	return *(P1++);
#else
	return getchar();
#endif
}
template<typename Tp> bool get1(Tp &x)
{
	bool neg = 0;
	char c = gc();
	while( c != EOF && (c < '0' || c > '9') && c != '-' ) c = gc();
	if(c == '-') c = gc(), neg = 1;
	if(c == EOF) return false;
	x = 0;
	for(; c>='0' && c<='9'; c = gc()) x = x*10 + c - '0';
	if(neg) x = -x;
	return true;
}
template<typename Tp> void printendl(Tp x)
{
	if(x<0)putchar('-'),x=-x;
	static short a[40], sz;
	sz = 0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
	puts("");
}
} // namespace IO
using IO::get1;
using IO::printendl;
#define get2(x,y) get1(x) && get1(y)
#define get3(x,y,z) get2(x,y) && get1(z)
#define get4(x,y,z,w) get3(x,y,z) && get1(w)
#define pb push_back
#define mp std::make_pair
#define ff first
#define ss second
typedef long long LL;
typedef unsigned long long uLL;
typedef std::pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const LL Linf = 1ll<<61;

const int maxn = 200111;

std::vector<int> g[maxn];
int n, m, stat[maxn];
void solve()
{
	get2(n, m);
	for(int i=1; i<=n; i++) g[i].clear();
	for(int i=1, u, v; i<=m; i++)
	{
		get2(u, v);
		g[v].pb(u);
	}
	
	std::vector<int> ans;
	for(int i=1; i<=n; i++)
	{
		stat[i] = 0;
		for(int j : g[i]) stat[i] = std::max(stat[i], stat[j] + 1);
		if(stat[i] == 2)
		{
			stat[i] = -1;
			ans.pb(i);
		}
	}
	printf("%d\n", (int)ans.size());
	for(int i=0; i<ans.size(); i++) printf("%d ", ans[i]);
	puts("");
}

int main()
{
	int tc;
	get1(tc);
	while(tc--) solve();
	return 0;
}
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

const int maxn = 1111;
int n, bad[maxn], mx, piv, cnt;
bool on[maxn];

void move()
{
	printf("%d", piv);
	int c = piv;
	for(int i=1; i<=n; i++) if(!bad[i] && !on[i])
	{
		on[i] = 1;
		c--;
		cnt++;
		printf(" %d", i);
		if(!c) break;
	}
	puts("");
	fflush(stdout);
	
	int x;
	get1(x);
	for(int i=1; i<=piv; i++)
	{
		if(on[x])
		{
			on[x] = 0;
			cnt--;
		}
		x++;
		if(x > n) x = 1;
	}
}

int main()
{
	get1(n);
	piv = 1;
	for(int i=1; i<=n; i++)
	{
		int now = n - i - (n + i - 1) / i + 1;
		if(mx < now)
		{
			mx = now;
			piv = i;
		}
	}
	for(int i=1; i<=n; i+=piv) bad[i] = 1;
	while(cnt < mx) move();
	puts("0");
	fflush(stdout);
	return 0;
}
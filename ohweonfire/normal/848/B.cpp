// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int n,w,h;pii ans[100111];
queue<int> q[400111];
vector<pii> vs[400111];
vector<pair<pii,int> > ver;
int main()
{
	get3(n,w,h);
	for(int i=1,g,p,t;i<=n;i++)
	{
		get3(g,p,t);
		if(g==1)ver.pb(mp(mp(p,t),i));
		else vs[p-t+100000].pb(mp(p,i));
	}
	for(int i=0;i<400111;i++)
	{
		sort(vs[i].begin(),vs[i].end());reverse(vs[i].begin(),vs[i].end());
		for(auto t:vs[i])q[i].push(t.ss);
	}
	sort(ver.begin(),ver.end());
	for(auto x:ver)
	{
		int tmp=x.ff.ff-x.ff.ss+100000;
		if(q[tmp].empty())ans[x.ss]=mp(x.ff.ff,h);
		else
		{
			int x2=q[tmp].front();q[tmp].pop();q[tmp].push(x.ss);
			ans[x2]=mp(x.ff.ff,h);
		}
	}
	for(int i=0;i<400111;i++)
	{
		for(auto x:vs[i])
		{
			int id=q[i].front();q[i].pop();
			ans[id]=mp(w,x.ff);
		}
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",ans[i].ff,ans[i].ss);
	return 0;
}
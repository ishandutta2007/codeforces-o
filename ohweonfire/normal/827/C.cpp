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

char s[100111],t[20];
int cnt[12][12][4][100111],id[256],n,q;
void add(int x,int*v,int val=1)
{
	for(;x<=n;x+=x&-x)
		v[x]+=val;
}
int query(int x,int*v)
{
	int ret=0;
	for(;x>0;x-=x&-x)
		ret+=v[x];
	return ret;
}
int main()
{
	id['A']=0;id['G']=1;id['C']=2;id['T']=3;
	scanf("%s%d",s+1,&q);n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		for(int t=1;t<=10;t++)
			add(i,cnt[t][i%t][id[s[i]]]);
	}
	for(int i=1,op,x,y;i<=q;i++)
	{
		get2(op,x);
		if(op==1)
		{
			scanf("%s",t);char& c=t[0];
			for(int t=1;t<=10;t++)
			{
				add(x,cnt[t][x%t][id[s[x]]],-1);
				add(x,cnt[t][x%t][id[c]]);
			}
			s[x]=c;
		}
		else
		{
			scanf("%d%s",&y,t);int m=strlen(t),ans=0;
			for(int j=0;j<m;j++)
				ans+=query(y,cnt[m][(x+j)%m][id[t[j]]])-query(x-1,cnt[m][(x+j)%m][id[t[j]]]);
			printendl(ans);
		}
	}
	return 0;
}
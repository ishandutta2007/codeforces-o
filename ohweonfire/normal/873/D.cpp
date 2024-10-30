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
const LL Linf=1ll<<62;
const double pi=acos(-1.0);

int n,k,a[100111];
void call(int l,int r,int vl,int vr)
{
	if(l==r-1)
	{
		a[l]=vl;
		return;
	}
	int mid=(l+r)>>1;
	if(k>=2)
	{
		k-=2;
		call(l,mid,vr-mid+l+1,vr);
		call(mid,r,vl,vr-mid+l);
	}
	else for(int i=0;i<r-l;i++)a[l+i]=vl+i;
}
int main()
{
	get2(n,k);
	if(k<1||k%2==0)
	{
		puts("-1");
		return 0;
	}
	call(0,n,1,n);
	if(k>1)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<n;i++)printf("%d ",a[i]);
	return 0;
}
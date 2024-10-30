/*
	Name: The Greatest Code of All Time
	Copyright: HaoBa IT Junior Two
	Author: OhWeOnFire
	Date: Today and Forever
	Description: This code is amazing, as you can see, right?
*/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define fortodo(i,m,n) for(int i=m;i<=n;i++)
#define hash orzYJZ
#define exp orzTZN
#define generate orzTBY
#define end orzMX
#define right orzYYT
#define sqr(x) ((x)*(x))
#define mem(x,y) memset((x),(y),sizeof(x))
#define abs(x) ((x)>0?(x):(-x))
#define get1(a) get_int(a)
#define get2(a,b) get1(a);get1(b)
#define get3(a,b,c) get1(a);get2(b,c)
#define printendl(a) print_int(a);puts("")
#define printspace(a) print_int(a);putchar(' ')

using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LF;
typedef pair<int,int> pii;

const int inf=0x7fffffff;
const LL Linf=(1uLL<<63)-1;
const double EPS=1e-10;

namespace IOSpace
{
	void get_int(int &x)
	{
		char t;
		bool neg=false;
		x=0;
		for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
		if(t=='-')neg=true,t=getchar();
		for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
		if(neg)x=-x;
	}
	void get_int(LL &x)
	{
		char t;
		bool neg=false;
		x=0;
		for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
		if(t=='-')neg=true,t=getchar();
		for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
		if(neg)x=-x;
	}
	void print_int(int x)
	{
		if(x<0)putchar('-'),x=-x;
		short a[20]= {},sz=0;
		while(x>0)a[sz++]=x%10,x/=10;
		if(sz==0)putchar('0');
		for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
	}
	void print_int(LL x)
	{
		if(x<0)putchar('-'),x=-x;
		short a[20]= {},sz=0;
		while(x>0)a[sz++]=x%10,x/=10;
		if(sz==0)putchar('0');
		for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
	}
}
using namespace IOSpace;

const int maxn=300005;
const int maxlog=20;
const LL mod=1000000007;

int n,k,a[maxn];
LL sum[maxn],dp[5005][5005];
int main()
{
	get2(n,k);
	for(int i=1;i<=n;i++)get1(a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)sum[i]=sum[i-1]+a[i]-a[i-1];
	dp[0][0]=0;
	int tmp=n%k,tt=n/k;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=tmp&&j<=i;j++)
		{
			dp[i][j]=Linf;
			if(i!=j)dp[i][j]=min(dp[i][j],dp[i-1][j]+sum[i*tt+j]-sum[i*tt+j-tt+1]);
			if(j!=0&&i!=0)dp[i][j]=min(dp[i][j],dp[i-1][j-1]+sum[i*tt+j]-sum[i*tt+j-tt]);
		}
	printendl(dp[k][tmp]);
	return 0;
}
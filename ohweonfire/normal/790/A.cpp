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

int n,k;
string s[55],ans[55],all[55];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n-k+1;i++)cin>>s[i];
	for(int i=1;i<=52;i++)
	{
		if(i<=26)all[i]=char('A'+i-1);
		else
		{
			all[i]="A";
			all[i]+=char('a'+i-27);
		}
	}
	for(int i=1;i<k;i++)ans[i]=all[i];
	for(int i=k;i<=n;i++)
	{
		if(s[i-k+1]=="NO")ans[i]=ans[i-k+1];
		else ans[i]=all[i];
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
	LL x;scanf("%lld",&x);
	int a[20],cnt=0;
	for(;x;a[++cnt]=x%10,x/=10);
	reverse(a+1,a+cnt+1);
	rep(i,cnt)
	{
		if(i==1&&a[i]==9)continue;
		if(9-a[i]>=a[i])continue;
		a[i]=9-a[i];
	}
	rep(i,cnt)printf("%d",a[i]);puts("");
    return 0;
}
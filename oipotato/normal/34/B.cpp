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
int n,m,a[1010];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	rep(i,m)ans+=max(0,-a[i]);
	printf("%d\n",ans);
    return 0;
}
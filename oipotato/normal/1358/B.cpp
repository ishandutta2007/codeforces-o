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
int a[100010],n;
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);rep(i,n)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ans=1;
		for(int i=n;i;i--)if(a[i]<=i){ans=i+1;break;}
		printf("%d\n",ans);
	}
    return 0;
}
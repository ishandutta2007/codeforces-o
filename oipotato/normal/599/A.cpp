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
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ans=a+b+c;
	ans=min(ans,2*(a+c));
	ans=min(ans,2*(a+b));
	ans=min(ans,2*(b+c));
	printf("%d\n",ans);
    return 0;
}
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
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n,k;scanf("%d%d",&n,&k);
		int len=(int)sqrt(n),x=-1;
		for(int i=2;i<=len;i++)if(n%i==0){x=i;break;}
		if(x==-1)x=n;
		if(x!=2)n+=x,k--;
		printf("%d\n",n+2*k);
	}
    return 0;
}
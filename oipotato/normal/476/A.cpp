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
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=-1;
	for(int i=0;i<=n/2;i++)
	{
		int tmp=n-i*2+i;
		if(tmp%m==0)
		{
			if(ans==-1||ans>tmp)ans=tmp;
		}
	}
	printf("%d\n",ans);
    return 0;
}
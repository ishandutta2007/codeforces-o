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
		char s[110];
		scanf("%s",s+1);
		int n=strlen(s+1);
		int l=1,r=n;
		for(;l<=n&&s[l]=='0';l++);
		for(;r&&s[r]=='0';r--);
		int ans=0;
		for(int i=l;i<=r;i++)if(s[i]=='0')ans++;
		printf("%d\n",ans);
	}
    return 0;
}
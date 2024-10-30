#include<cmath>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#define LL long long
#define ll long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int Maxn=200005;
vector<int> G[Maxn];
int d[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
		d[a]++;d[b]++;
	}
	vector<int> l;
	int cnt=0,id=-1;
	for (int i=1;i<=n;i++){
		if (d[i]==1) l.pb(i);
		if (d[i]>2){
			id=i;
			cnt++;
		}
	}
	if (cnt>=2){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	if (cnt==0){
		printf("1\n%d %d\n",l[0],l[1]);
		return 0;
	}
	printf("%d\n",l.size());
	for (int i=0;i<l.size();i++){
		printf("%d %d\n",id,l[i]);
	}
	return 0;
}
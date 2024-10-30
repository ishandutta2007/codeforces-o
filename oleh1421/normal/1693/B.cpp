#pragma GCC optimize("Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1000510;
const int inf=1e9;
const ll mod=1000000007;
int a[N];
int p[N];
vector<int>g[N];
ll l[N],r[N];
ll dp[N];
int ans=0;
void dfs(int v){
    dp[v]=0;
    for (int to:g[v]){
        dfs(to);
        dp[v]+=dp[to];
    }
    if (dp[v]<l[v]){
        dp[v]=r[v];
        ans++;
    } else if (dp[v]>r[v]) dp[v]=r[v];
}
void solve(int Case){
    int n;cin>>n;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=2;i<=n;i++){
        cin>>p[i];
        g[p[i]].push_back(i);
    }
    for (int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }
    ans=0;
    dfs(1);
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
5 10
ABAAA


1000000000

100000000
0 1
1 0 1 0 1 0 1 0 1 0 0 0
9 2 1 4 3 6 5 8 7 10 11 12

C(n-1,(n-1)/2)
 1 1 2 3 6 10 20 35 70 12
dp[i] = (i%2==1 ? dp[i-1]*2 : (dp[i-1]/4)*3);
**/
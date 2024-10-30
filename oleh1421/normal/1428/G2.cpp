#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const int N=1000000;
const ll inf=1000000000000000001;
const ll mod=998244353;
ll F[6];
ll dp[N];
ll val[N];
void solve(){
    int k;cin>>k;
    for (int i=0;i<6;i++) cin>>F[i];
    dp[0]=0;
    for (int i=1;i<N;i++) dp[i]=-inf;
    ll pw=1ll;
    vector<pair<int,ll> >v;
    for (int i=0;i<6;i++){
        int x=min(3ll*(k-1),(N-1)/(pw*3));

        for (int j=1;j<=x;j*=2){
            v.push_back({pw*3*j,F[i]*j});
            x-=j;
        }
        if (x){
            v.push_back({pw*3*x,F[i]*x});
        }
        for (int j=1;j<10;j++){
            ll val=0ll;
            if (j%3==0) val=F[i]*(j/3);
        }
//        pw*3 - F[i]
        pw*=10ll;
    }
    for (auto cur:v){
//        cout<<"OK"<<" "<<cur.first<<endl;
        for (int j=N-1;j>=cur.first;j--){
//            cout<<j-cur.first<<endl;
            dp[j]=max(dp[j],dp[j-cur.first]+cur.second);
        }
    }
    pw=1;
//    for (int i=0;i<100;i++) cout<<i<<" "<<dp[i]<<endl;
    for (int i=0;i<6;i++){
        for (int j=N-1;j>=0;j--){
            for (int t=1;t<=9 && t*pw<=j;t++){
                ll cur=0ll;
                if (t%3==0) cur=F[i]*(t/3ll);
                dp[j]=max(dp[j],dp[j-t*pw]+cur);
            }
        }
        pw*=10ll;
    }
    int q;cin>>q;
    for (int it=1;it<=q;it++){
        int n;cin>>n;
        cout<<dp[n]<<endl;
    }

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/**
2 998244353

**/
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=100010;
int p[N];
void solve(){
    int n;cin>>n;
    vector<int>v,u;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        if (x%2) v.push_back(x);
        else u.push_back(x);
    }
    if (is_sorted(v.begin(),v.end()) && is_sorted(u.begin(),u.end())){
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }


}

int32_t  main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;

    while (tt--){
        solve();
    }
    return 0;
}

/**
1
4 2
1 2
1 3
1 4
**/
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
#include<unordered_set>

using namespace std;

/*

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> st;

*/
/*

st.find_by_order();
st.order_of_key();

*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t, j = 0, ans = 1e18;
    cin >> n >> t;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        int anss;
        if (v[i].first > t){
            anss = v[i].first;
            if (anss < ans){
                ans = anss;
                j = i;
            }
        }
        else{
            anss = (t - v[i].first + v[i].second - 1) / v[i].second * v[i].second + v[i].first;
            if (anss < ans){
                ans = anss;
                j = i;
            }
        }
    }
    cout << j + 1 << endl;
    return 0;
}
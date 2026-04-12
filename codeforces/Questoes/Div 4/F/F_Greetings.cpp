#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

template<class T> using ordered_set = 
tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(), [&](pair<int, int> x, pair<int, int> y){
        if (x.first != y.first) return x.first > y.first;
        return x.second > y.second;
    });

    ll ans = 0;
    ordered_set<pair<int, int>> order;
    int idx = 0;
    for (int i = 0; i < n; i++){
        int l = p[i].first;
        int r = p[i].second;

        int sum = order.order_of_key({r, 0}) - order.order_of_key({l-1, 0});
        ans += sum;

        order.insert({r, idx++});
    }

    cout << ans << "\n";
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        solve();
    }
}
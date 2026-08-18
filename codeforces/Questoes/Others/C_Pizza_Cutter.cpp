#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n, m; cin >> n >> m;

    ll hh, vv; cin >> hh >> vv;
    vector<pair<int, int>> h(hh), v(vv);
    for (auto &[i, j] : h) cin >> i >> j;
    for (auto &[i, j] : v) cin >> i >> j;

    sort(h.begin(), h.end());
    sort(v.begin(), v.end());

    ll ans = (hh+1) * (vv+1);

    ordered_set<int> order, order2;
    for (int i = hh-1; i >= 0; i--){
        ans += order.order_of_key(h[i].second);
        order.insert(h[i].second);
    }
    for (int i = vv-1; i >= 0; i--){
        ans += order2.order_of_key(v[i].second);
        order2.insert(v[i].second);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}

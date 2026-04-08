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
    int n, q; cin >> n >> q;

    ordered_set<int> order;
    vector<int> sal(n);
    for (int i = 0; i < n; i++){
        cin >> sal[i];
        order.insert(sal[i]);
    }

    while(q--){
        char c; cin >> c;
        if (c == '?'){
            int l, r; cin >> l >> r;

            cout << order.order_of_key(r+1) - order.order_of_key(l) << "\n";
        }
        else {
            int idx, v; cin >> idx >> v;
            idx--;

            order.erase(order.find_by_order(order.order_of_key(sal[idx])));

            sal[idx] = v;
            order.insert(v);
        }
    }
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
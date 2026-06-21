#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

template<class T> using ordered_set = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
K-TH(S) : return the k-th smallest element of S
COUNT(S,x): return the number of elements of S smaller than x
*/

void solve(){
    int n; cin >> n;

    ordered_set<int> order;
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        int v; cin >> v;

        if (c == 'I') order.insert(v);
        else if (c == 'D') order.erase(v);
        else if (c == 'C'){
            cout << order.order_of_key(v) << "\n";
        }
        else {
            if (v > order.size()) {
                cout << "invalid" << "\n";
            }
            else {
                int vv = *order.find_by_order(v - 1);
                cout << vv << "\n";
            }
        }
    }
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
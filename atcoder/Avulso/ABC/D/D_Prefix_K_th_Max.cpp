#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

void solve(){
    int n, idx; cin >> n >> idx;

    indexed_multiset mult;

    for (int i = 0; i < n; i++){
        int x; cin >> x;

        mult.insert(x);

        if (i + 1 >= idx){
            cout << *mult.find_by_order(i-idx+1) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
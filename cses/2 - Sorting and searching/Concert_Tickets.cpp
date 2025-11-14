#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    
    multiset<int> arr;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr.insert(x);
    }

    while(m--){
        int x; cin >> x;

        auto it = arr.upper_bound(x);

        if (*it != 0) it--;

        if (it == arr.end() || *it > x) cout << -1 << "\n";
        else {
            cout << *it << "\n";
            arr.erase(it);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
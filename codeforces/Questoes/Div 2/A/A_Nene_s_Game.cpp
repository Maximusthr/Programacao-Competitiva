#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int k, q; cin >> k >> q;

    vector<int> num(k);
    for (auto &i : num) cin >> i;

    while(q--){
        int x; cin >> x;
        if (num[0] <= x){
            cout << num[0] - 1 << " ";
        }
        else cout << x << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
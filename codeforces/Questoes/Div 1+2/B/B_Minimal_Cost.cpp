#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, u, v; cin >> n >> u >> v;

    vector<int> d(n);
    for (auto &i : d) cin >> i;

    for (int i = 1; i < n; i++){
        if (abs(d[i] - d[i-1]) >= 2){
            cout << 0 << "\n";
            return;
        }
    }

    int ans = 2e9;
    for (int i = 1; i < n; i++){
        if (d[i] == d[i-1]){
            ans = min({ans, v + v, u + v});
        }
        else if (abs(d[i] - d[i-1]) == 1){
            ans = min({ans, u, v});
        }
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
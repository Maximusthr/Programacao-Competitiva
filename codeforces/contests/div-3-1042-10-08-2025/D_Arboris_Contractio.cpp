//UPSOLVE

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int unico = 0;
    for (int i = 0; i < n; i++){
        if (g[i].size() == 1) unico++;
    }
    int ans = n;
    for (int i = 0; i < n; i++){
        int curr = unico;
        if (g[i].size() == 1) curr--;

        for (auto u : g[i]){
            if (g[u].size() == 1) curr--;
        }

        ans = min(ans, curr);
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
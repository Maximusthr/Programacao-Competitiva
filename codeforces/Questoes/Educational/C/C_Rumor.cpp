#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<ll> c(n);
    for (auto &i : c) cin >> i;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<bool> vis(n);

    auto dfs = [&](auto self, int u, ll &coins) -> void {
        if (!vis[u]) vis[u] = true;

        coins = min(coins, c[u]);

        for (auto v : g[u]){
            if (!vis[v]) {
                self(self, v, coins);
            }
        }
    };

    ll ans = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            ll coins = LINF;

            dfs(dfs, i, coins);

            ans += coins;
        }
    }

    cout << ans << "\n";
}
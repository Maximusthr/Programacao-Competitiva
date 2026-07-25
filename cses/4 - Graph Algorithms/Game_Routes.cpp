#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }

    vector<ll> dp(n);
    dp[0] = 1;
    
    vector<int> topo;
    vector<bool> vis(n);
    auto dfs = [&](auto &&self, int u) -> void {
        vis[u] = true;
        for (auto v : g[u]){
            if (!vis[v]) self(self, v);
        }
        topo.push_back(u);
    };
    dfs(dfs, 0);

    reverse(topo.begin(), topo.end());

    for (auto u : topo){
        for (auto v : g[u]){
            dp[v] += dp[u];
            dp[v] %= MOD;
        }
    }

    cout << dp[n-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
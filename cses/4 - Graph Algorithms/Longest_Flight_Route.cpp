#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }

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

    vector<int> dp(n);
    vector<int> pai(n);
    for (auto u : topo){
        int x = dp[u] + 1;

        for (auto v : g[u]){
            if (x > dp[v]) {
                pai[v] = u;
                dp[v] = x;
            }
        }
    }

    if (dp[n-1] == 0){
        cout << "IMPOSSIBLE" << "\n";
        return;
    }

    vector<int> path;
    for (int p = n-1; p != 0; p = pai[p]){
        path.push_back(p);
    }
    path.push_back(0);
    
    reverse(path.begin(), path.end());
    
    cout << path.size() << "\n";
    for (auto v : path) cout << v + 1 << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
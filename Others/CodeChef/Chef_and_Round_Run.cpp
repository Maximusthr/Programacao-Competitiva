#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<vector<int>> g(n), g_rev(n);
    vector<int> topo, order;
    vector<bool> vis(n);

    auto dfs1 = [&](auto &&self, int u) -> void {
        if (!vis[u]) vis[u] = true;
        for (auto v : g[u]){
            if (!vis[v]) self(self, v);
        }
        topo.push_back(u);
    };

    auto dfs2 = [&](auto &&self, int u) -> void {
        if (!vis[u]) vis[u] = true;
        for (auto v : g_rev[u]){
            if (!vis[v]) self(self, v);
        }
        order.push_back(u);
    };

    int ans = 0;

    for (int i = 0; i < n; i++){
        int x = (arr[i] + i + 1) % n;

        g[i].push_back(x);
        g_rev[x].push_back(i);

        if (i == x) ans++;
    }

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs1(dfs1, i);
        }
    }

    reverse(topo.begin(), topo.end());
    vis.assign(n, false);

    for (auto u : topo){
        if (!vis[u]) {
            dfs2(dfs2, u);
            if (order.size() > 1) ans += order.size();
            order.clear();
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
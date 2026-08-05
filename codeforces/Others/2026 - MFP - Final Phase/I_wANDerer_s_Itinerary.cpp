#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++){
        int x, y, c; cin >> x >> y >> c;
        x--, y--;
        g[x].push_back({y, c});
    }

    vector<bool> foi(n);
    auto dfs = [&](auto &&self, int u) -> void {
        foi[u] = true;
        for (auto [v, w] : g[u]){
            if (!foi[v]) self(self, v);
        }
    };

    dfs(dfs, 0);
    if (!foi[n-1]) {
        cout << -1 << "\n";
        return;
    }

    int ans = 0;
    
    auto bfs = [&](int bit) -> bool {
        queue<int> q;
        vector<bool> vis(n);
        vis[0] = true;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for (auto [v, w] : g[u]){
                if (!vis[v] && (w & bit) >= bit){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        return vis[n-1];
    };

    for (int i = 30; i >= 0; i--){
        ans |= (1 << i);
        if (!bfs(ans)){
            ans ^= (1 << i);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
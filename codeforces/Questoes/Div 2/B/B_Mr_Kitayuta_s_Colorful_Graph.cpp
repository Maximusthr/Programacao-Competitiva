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
        x--, y--, c--;
        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }

    vector<bool> vis(n);

    vector<vector<int>> ans(n, vector<int> (n));

    set<int> edges;

    auto dfs = [&](auto &&self, int u, int type) -> void {
        if (!vis[u]) vis[u] = true;

        for (auto v : g[u]){
            if (v.second == type){
                if (!vis[v.first]){
                    edges.insert(u);
                    edges.insert(v.first);
                    self(self, v.first, type);
                }
            }
        }
    };

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (!vis[j]) {
                dfs(dfs, j, i);
            }

            vector<int> talvez = {edges.begin(), edges.end()};

            for (int k = 0; k < talvez.size(); k++){
                for (int l = k + 1; l < talvez.size(); l++){
                    ans[talvez[k]][talvez[l]]++;
                    ans[talvez[l]][talvez[k]]++;
                }
            }

            edges.clear();
        }

        vis.assign(n, false);
    }

    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        x--, y--;

        cout << ans[x][y] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
        solve();
    // }
}
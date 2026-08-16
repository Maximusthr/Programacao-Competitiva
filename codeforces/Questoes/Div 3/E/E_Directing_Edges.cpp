#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    vector<pair<int, int>> ans;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++){
        int tipo, x, y; cin >> tipo >> x >> y;
        x--, y--;
        if (tipo == 0){
            edges.push_back({x, y});
        }
        else {
            g[x].push_back(y);
            ans.push_back({x, y});
        }
    }

    bool ok = true;
    vector<int> color(n);
    vector<int> topo;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        color[u] = 1;
        for (auto v : g[u]){
            if (v == p) continue;
            if (color[v] == 0) self(self, v, u);
            if (color[v] == 1){
                ok = false;
                return;
            }
        }
        topo.push_back(u);
        color[u] = 2;
    };

    for (int i = 0; i < n; i++){
        if (color[i] == 0){
            dfs(dfs, i, -1);
        }
    }

    if (!ok){
        cout << "NO" << "\n";
        return;
    }

    reverse(topo.begin(), topo.end());

    vector<int> pos(n);
    for (int i = 0; i < n; i++){
        pos[topo[i]] = i;
    }   

    for (auto [x, y] : edges){
        if (pos[x] < pos[y]) ans.push_back({x, y});
        else ans.push_back({y, x});
    }

    cout << "YES" << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}

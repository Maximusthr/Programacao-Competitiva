#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
const int MAX = 103;

vector<vector<int>> g(MAX);
vector<bool> vis(MAX);
vector<vector<bool>> caminhos(MAX, vector<bool> (MAX));
vector<pair<int, int>> paths;

void dfs(int u){
    if (!vis[u]){
        vis[u] = true;
    }

    for (auto v : g[u]){
        if (!caminhos[u][v] || !caminhos[v][u]) continue;
        if (!vis[v]){
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    while(cin >> n >> m && (n || m)) {
        
        for (int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
    
            g[x].emplace_back(y);
            g[y].emplace_back(x);
            caminhos[x][y] = true;
            caminhos[y][x] = true;
            paths.emplace_back(x, y);
            paths.emplace_back(y, x);
        }
        
        bool ok = true;
        for (int i = 0; i < paths.size(); i++){
            caminhos[paths[i].first][paths[i].second] = false;
            caminhos[paths[i].second][paths[i].first] = false;
    
            dfs(paths[i].first);
    
            for (int i = 0; i < n; i++){
                if (!vis[i]) {
                    ok = false;
                    cout << "Yes" << "\n";
                    break;
                }
            }
            if (!ok) break;
            caminhos[paths[i].first][paths[i].second] = true;
            caminhos[paths[i].second][paths[i].first] = true;
    
            vis.assign(MAX, false);
        }
    
        if (ok) cout << "No" << "\n";
    
        g.assign(MAX, vector<int> ());
        vis.assign(MAX, false);
        caminhos.assign(MAX, vector<bool> (MAX));
        paths.clear();
    }
}
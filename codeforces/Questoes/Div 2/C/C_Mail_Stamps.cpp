#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> indices;

int getCompressed(int a){
    return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
}

void solve(){
    // dava pra só usar map =)

    int n; cin >> n;

    vector<int> a; // indicies originais
    
    map<int, pair<int, int>> mapa;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        mapa[i] = {x, y};
        a.push_back(x);
        a.push_back(y);
    }
    
    indices = a; // compressão nos indices
    sort(indices.begin(), indices.end());
    indices.resize(unique(indices.begin(), indices.end()) - indices.begin());
    
    vector<vector<int>> g(n+2);
    for (auto [x, y] : mapa){
        g[getCompressed(y.first)].push_back(getCompressed(y.second));
        g[getCompressed(y.second)].push_back(getCompressed(y.first));
    }

    vector<int> path;
    vector<bool> vis(n);

    auto dfs = [&](auto &&self, int u) -> void {
        if (!vis[u]) vis[u] = true;

        path.push_back(u);

        for (auto v : g[u]){
            if (!vis[v]){
                self(self, v);
            }
        }
    };

    for (int i = 0; i <= n; i++){
        if (!vis[i] && g[i].size() == 1){
            dfs(dfs, i);
        }
    }

    for (int i = 0; i < path.size(); i++){
        cout << indices[path[i]] + 1 << " \n" [i == path.size()];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
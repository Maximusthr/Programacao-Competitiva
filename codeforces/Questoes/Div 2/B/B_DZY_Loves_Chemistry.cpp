#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    vector<bool> vis(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    ll ans = 1;

    auto dfs = [&](auto self, int u) -> void {
        if (!vis[u]) vis[u] = true;

        for (auto v : g[u]){
            if (!vis[v]){
                self(self, v);
                ans *= 2;
            }
        }
    };

    ll aux = 1;
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(dfs, i);
            aux = max(aux, ans);
        }
    }

    cout << aux << "\n";
}
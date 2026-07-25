#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;
    vector<bool> foi(n);
    vector<bool> vis(n);
    
    auto dfs = [&](auto &&self, int u, int p) -> void {
        vis[u] = true;
        for (auto v : g[u]){
            if (!vis[v]){
                self(self, v, u);
            }
        }
        if (p != -1){
            if (!foi[p] && !foi[u]){
                foi[p] = true;
                foi[u] = true;
                ans++;
            }
        }
    };

    dfs(dfs, 0, -1);

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
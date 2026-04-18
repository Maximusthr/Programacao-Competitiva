#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+10;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }

    vector<bool> vis(n);

    set<int> ans;
    auto dfs = [&](auto &&self, int u) -> void {
        if (!vis[u]) vis[u] = true;

        ans.insert(u);

        for (auto v : g[u]){
            if (!vis[v]){
                self(self, v);
            }
        }
    };
    
    dfs(dfs, 0);

    cout << ans.size() << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
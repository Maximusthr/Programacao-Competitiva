#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    vector<bool> vis(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;

    vector<int> prof(n);
    auto dfs = [&](auto &&self, int u, int depth) -> void {
        if (!vis[u]) vis[u] = true;

        prof[depth]++;

        int count = 0;
        for (auto x : g[u]){
            if (!vis[x]) count++;
        }

        if (count) count++;

        ans = max(ans, count);
        ans = max(ans, prof[depth]);

        for (auto v : g[u]){
            if (!vis[v]){
                self(self, v, depth + 1);
            }
        }
    };

    dfs(dfs, 0, 0);

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> v(n);
    for (auto &i : v) cin >> i;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> dist(n);

    auto dfs = [&](auto &&self, int u, int p) -> void {
        for (auto v : g[u]){
            if (v == p) continue;
            dist[v] = dist[u] + 1;
            self(self, v, u);
        }
    };

    dfs(dfs, 0, -1);

    int ans = 0;

    auto dfs2 = [&](auto &&self, int u, int p) -> bool {
        bool vis = v[u] > k;

        for (auto v : g[u]){
            if (v == p) continue;
            bool x = self(self, v, u);
            ans += (x ? 2 : 0);
            if (x) vis = true;
        }   

        return vis;
    };

    dfs2(dfs2, 0, -1);

    int big = 0;
    for (int i = 0; i < n; i++){
        if (v[i] > k) big = max(big, dist[i]);
    }

    cout << ans - big << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
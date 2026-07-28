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

    vector<int> dp1(n), dp2(n);

    auto dfs = [&](auto &&self, int u, int p) -> void {
        for (auto v : g[u]){
            if (v == p) continue;

            self(self, v, u);
            dp2[u] += max(dp1[v], dp2[v]);
        }
        for (auto v : g[u]){
            if (v == p) continue;

            dp1[u] = max(dp1[u], dp2[v] + 1 + dp2[u] - max(dp1[v], dp2[v]));
        }
    };

    dfs(dfs, 0, -1);

    cout << max(dp1[0], dp2[0]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
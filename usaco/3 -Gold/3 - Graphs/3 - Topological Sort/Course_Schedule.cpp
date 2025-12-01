#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }

    vector<int> color(n);

    vector<int> order;

    auto dfs = [&](auto &&self, int u) -> void {
        color[u] = 1;

        for (auto v : g[u]){
            if (color[v] == 0) self(self, v);
            if (color[v] == 1){
                cout << "IMPOSSIBLE" << "\n";
                exit(0);
            }
        }

        color[u] = 2;
        order.push_back(u);
    };

    for (int i = 0; i < n; i++){
        if (color[i] == 0){
            dfs(dfs, i);
        }
    }

    reverse(order.begin(), order.end());

    for (auto &i : order) cout << i + 1 << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
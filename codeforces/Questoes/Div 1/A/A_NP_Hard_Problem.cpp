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
        g[y].push_back(x);
    }

    vector<int> color(n, -1);
    bool ok = true;
    auto dfs = [&](auto &&self, int u, int c) -> void {
        if (color[u] == -1) {
            color[u] = c;
        }
        for (auto v : g[u]){
            if (color[v] == -1){
                self(self, v, c ^ 1);
            }
            else if (color[v] == color[u]) {
                ok = false;
                return;
            }
        }
    };

    for (int i = 0; i < n; i++){
        if (color[i] == -1){
            dfs(dfs, i, 0);
        }
    }

    if (!ok){
        cout << -1 << "\n";
        return;
    }

    vector<int> r, b;
    for (int i = 0; i < n; i++){
        if (!color[i]) r.push_back(i);
        else b.push_back(i);
    }

    cout << r.size() << "\n";
    for (auto &i : r) cout << i + 1 << " ";
    cout << "\n";
    cout << b.size() << "\n";
    for (auto &i : b) cout << i + 1 << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
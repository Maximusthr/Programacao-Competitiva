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

    vector<int> pai(n);
    vector<int> color(n);
    int st = -1, end = -1;

    bool ok = false;
    auto dfs = [&](auto &&self, int u) -> void {
        color[u] = 1;
        for (auto v : g[u]){
            if (color[v] == 0) {
                pai[v] = u;
                self(self, v);
            }
            else if (color[v] == 1){
                st = v;
                end = u;
                ok = true;
            }
        }
        color[u] = 2;
    };

    for (int i = 0; i < n; i++){
        if (color[i] == 0){
            dfs(dfs, i);
            if (ok) break;
        }
    }

    if (end == -1){
        cout << "IMPOSSIBLE" << "\n";
    }
    else {
        vector<int> path;
        path.push_back(st);

        for (int u = end; u != st; u = pai[u]){
            path.push_back(u);
        }

        path.push_back(st);

        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for (auto &i : path) cout << i + 1 << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
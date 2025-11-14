#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> pai(n, -1);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        x--;

        if (x == i) continue;

        g[x].push_back(i);
        g[i].push_back(x);
        pai[i] = x;
    }

    if (n == 1){
        cout << 1 << "\n" << 1 << "\n" << 1 << "\n";
        return;
    }

    vector<bool> vis(n);
    vector<vector<int>> path(n);

    auto dfs = [&](auto &&self, int u, int i) -> void {
        if (!vis[u]) vis[u] = true;

        while(pai[u] != -1 && !vis[pai[u]]){
            path[i].push_back(u);
            u = pai[u];
            vis[u] = true;
        }
        if (u != -1) path[i].push_back(u);
    };

    int idx = 0;
    for (int i = 0; i < n; i++){
        if (g[i].size() == 1 && !vis[i] && pai[i] != -1){
            dfs(dfs, i, idx++);
        }
    }

    int tem = 0;
    for (int i = 0; i < n; i++){
        if (path[i].size() == 0) break;
        else {
            reverse(path[i].begin(), path[i].end());
            tem++;
        }
    }

    cout << tem << "\n";
    for (int i = 0; i < tem; i++){
        cout << path[i].size() << "\n";
        for (int j = 0; j < path[i].size(); j++){
            cout << path[i][j] + 1 << " \n"[j == path[i].size() - 1];
        }
    }

    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
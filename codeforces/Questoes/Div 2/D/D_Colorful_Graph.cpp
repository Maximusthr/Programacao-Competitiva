#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> color(n);
    int maior = 0;
    for (int i = 0; i < n; i++){
        cin >> color[i];
        maior = max(maior, color[i]);
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        if (color[x] == color[y]) continue;
        g[x].push_back(y);
        g[y].push_back(x);
    }   

    vector<bool> vis(n);
    vector<set<int>> tudo(maior+1);

    auto dfs = [&](auto &&self, int u) -> void {
        vis[u] = true;

        for (auto v : g[u]){
            tudo[color[u]].insert(color[v]);
        }

        for (auto v : g[u]){
            if (!vis[v]) self(self, v);
        }
    };

    for (int i = 0; i < n; i++){
        if (!vis[i]) dfs(dfs, i);
    }

    pair<ll, ll> mai = {INF, -1};
    for (int i = 0; i < n; i++){
        int x = tudo[color[i]].size();
        if (x == mai.second){
            if (mai.first > color[i]) mai = {color[i], x};
        }
        else if (x > mai.second) mai = {color[i], x};
    }

    cout << mai.first << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}

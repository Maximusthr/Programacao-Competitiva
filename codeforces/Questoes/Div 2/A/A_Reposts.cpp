#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    int id = 1;
    map<string, int> mapa;
    vector<vector<int>> g(n+5);
    for (int i = 0; i < n; i++){
        string a, b, c; cin >> a >> b >> c;

        for (int i = 0; i < a.size(); i++){
            a[i] = tolower(a[i]);
        }
        for (int i = 0; i < c.size(); i++){
            c[i] = tolower(c[i]);
        }

        if (mapa[c] == 0) mapa[c] = id++;
        if (mapa[a] == 0) mapa[a] = id++;

        g[mapa[c]].push_back(mapa[a]);
        g[mapa[a]].push_back(mapa[c]);
    }

    int ans = 0;
    int aux = 0;
    vector<bool> vis(n+1);

    auto dfs = [&](auto self, int u) -> void {
        if (!vis[u]) vis[u] = true;

        aux++;
        ans = max(ans, aux);

        for (auto v : g[u]){
            if (!vis[v]){
                self(self, v);
            }
        }

        aux--;
    };

    dfs(dfs, 1);

    cout << ans << "\n";
}
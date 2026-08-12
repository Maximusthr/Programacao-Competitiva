#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    map<pair<int, int>, int> mapa;
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        mapa[{x, y}] = i;
        mapa[{y, x}] = i;
    }

    for (int i = 0; i < n; i++){
        if (g[i].size() >= 3){
            cout << -1 << "\n";
            return;
        }
    }

    vector<int> val(n, -1);
    vector<bool> vis(n);
    auto dfs = [&](auto &&self, int u, int p, int last) -> void {
        if (!vis[u]) vis[u] = true;

        if (last != -1){
            val[mapa[{u, last}]] = p;
        }

        int aux = 0;

        for (auto v : g[u]){
            if (!vis[v]){
                if (last == -1) {
                    aux++;
                    int x = p ^ 1;
                    if (aux == 2) self(self, v, x, u);
                    else self(self, v, p, u);
                }
                else self(self, v, p ^ 1, u);
            }
        }
    };
    
    dfs(dfs, 0, 0, -1);
    
    for (int i = 0; i < n-1; i++){
        if (val[i] & 1) cout << 3 << " ";
        else cout << 2 << " ";
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

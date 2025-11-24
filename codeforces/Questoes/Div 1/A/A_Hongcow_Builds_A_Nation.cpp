#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    
    vector<int> special(k);

    for (int i = 0; i < k; i++){
        cin >> special[i];
        special[i]--;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<bool> vis(n);
    
    int aux = 0;

    auto dfs = [&](auto &&self, int u) -> void {
        if (!vis[u]) {
            vis[u] = true;
            aux++;
        }

        for (auto v : g[u]){
            if (!vis[v]){
                self(self, v);
            }
        }
    };

    vector<int> comp;
    for (int i = 0; i < k; i++){
        dfs(dfs, special[i]);
        comp.push_back(aux);
        aux = 0;
    }

    sort(comp.begin(), comp.end(), greater<int> ());

    for (int i = 0; i < n; i++){
        if (!vis[i]) comp[0]++;
    }

    ll ans = 0;
    for (auto x : comp){
        ans += x * (x-1)/2;
    }
    
    cout << ans - m << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
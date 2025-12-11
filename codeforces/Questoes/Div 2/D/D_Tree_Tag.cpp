#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, a, b, da, db; cin >> n >> a >> b >> da >> db;

    a--, b--;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    if (2 * da >= db){
        cout << "Alice" << "\n";
        return;
    }

    vector<int> dist_a(n, -1);

    auto dfs = [&](auto &&self, int u, int d, vector<int> &dist) -> void {
        dist[u] = d;

        for (auto v : g[u]){
            assert(v < n);
            if (dist[v] == -1){
                self(self, v, d+1, dist);
            }
        }
    };

    dfs(dfs, a, 0, dist_a);

    if (da >= dist_a[b]){
        cout << "Alice" << "\n";
        return;
    }

    // vamos deixar alice no meio da arvore
    vector<int> diam(n, -1);
    dfs(dfs, b, 0, diam);
    pair<int, int> maior = {-1, -1};
    for (int i = 0; i < n; i++){
        if (maior.first < diam[i]){
            maior.first = diam[i];
            maior.second = i;
        }
    }

    diam.clear();
    diam.assign(n, -1);
    dfs(dfs, maior.second, 0, diam);

    for (int i = 0; i < n; i++){
        if (maior.first < diam[i]){
            maior.first = diam[i];
            maior.second = i;
        }    
    }
    
    if (2 * da >= maior.first){
        cout << "Alice" << "\n";
    }
    else {
        cout << "Bob" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
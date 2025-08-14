#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3001;

vector<vector<int>> g(MAX);
vector<bool> vis(MAX);
vector<bool> retirados(MAX);

int comp = 0;
int dfs(int u){
    vis[u] = true;
    
    comp++;

    for (auto v : g[u]){
        if (retirados[v]) continue;
        if (!vis[v]) {
            dfs(v);
        }
    }
    return comp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int total = 0;
    int componentes;

    for (int i = 0; i < n; i++){
        bool ok = false;
        for (int i = 0; i < n; i++){
            if (!retirados[i]) {
                componentes = dfs(i);
                ok = true;
            }
            if (ok) break;
        }
        if (componentes == n-total) cout << "YES" << "\n";
        else cout << "NO" << "\n";

        int x; cin >> x;
        x--, total++;

        retirados[x] = true;
        vis.assign(MAX, false);
        comp = 0;
    }
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g, g_rev;
vector<vector<int>> comp, cond;
vector<int> topo, order;
vector<bool> vis;

void dfs(int u){
    if (!vis[u]) vis[u] = true;
    for (auto v : g[u]){
        if (!vis[v]) dfs(v);
    }
    topo.push_back(u);
}

void dfs2(int u){
    if (!vis[u]) vis[u] = true;
    for (auto v : g_rev[u]){
        if (!vis[v]) dfs2(v);
    }
    order.push_back(u);
}

int last = 0, qtd = 0;
void dfs3(int u){
    if (!vis[u]) vis[u] = true;

    if (cond[u].size() == 0) {
        last = u;
        qtd++;
    }

    for (auto v : cond[u]){

        if (!vis[v]) {
            dfs3(v);
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;

    g.resize(n), g_rev.resize(n);
    vis.resize(n);

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g_rev[y].push_back(x);
    }

    for (int i = 0; i < n; i++){
        if (!vis[i]) dfs(i);
    }

    vis.assign(n, false);

    reverse(topo.begin(), topo.end());

    for (auto u : topo){
        if (!vis[u]){
            dfs2(u);
            comp.push_back(order);
            order.clear();
        }
    }

    vector<int> roots(n, -1);
    for (int i = 0; i < comp.size(); i++){
        int x = comp[i][0];
        for (auto u : comp[i]){
            roots[u] = x;
        }
    }
    cond.resize(n);
    for (int i = 0; i < n; i++){
        for (auto u : g[i]){
            if (roots[i] == roots[u]) continue;
            cond[roots[i]].push_back(roots[u]);
        }
    }

    vis.assign(n, false);

    for (auto i : topo){
        if (!vis[roots[i]]) dfs3(roots[i]);
    }

    if (qtd > 1){
        cout << 0 << "\n";
        return;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (roots[i] == last) ans.push_back(i+1);
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " \n"[i+1 == ans.size()];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
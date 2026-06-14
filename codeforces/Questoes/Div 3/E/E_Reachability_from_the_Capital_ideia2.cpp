#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g, g_rev;
vector<vector<int>> cond;
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

void dfs3(int u){
    if (!vis[u]) vis[u] = true;
    for (auto v : cond[u]){
        if (!vis[v]) dfs3(v);
    }
}

void solve(){
    int n, m, s; cin >> n >> m >> s;
    s--;

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

    reverse(topo.begin(), topo.end());
    vis.assign(n, false);

    vector<int> roots(n);

    for (auto u : topo){
        if (!vis[u]){
            dfs2(u);
            int x = order[0];
            for (auto v : order){
                roots[v] = x;
            }
            order.clear();
        }
    }

    cond.resize(n);
    vector<int> degree(n);
    for (int i = 0; i < n; i++){
        for (auto v : g[i]){
            if (roots[i] != roots[v]){
                cond[roots[i]].push_back(roots[v]);
                degree[roots[v]]++;
            }
        }
    }

    vis.assign(n, false);

    int ans = 0;
    dfs3(roots[s]);
    for (int i = 0; i < n; i++){
        if (!vis[roots[i]] && !degree[roots[i]]) {
            ans++;
            vis[roots[i]] = 1;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
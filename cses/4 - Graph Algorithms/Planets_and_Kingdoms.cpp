#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g, g_rev;
vector<bool> vis;
vector<int> topo, order;

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
        if (!vis[i]){
            dfs(i);
        }
    }

    reverse(topo.begin(), topo.end());

    vector<vector<int>> scc;
    vis.assign(n, false);
    for (auto u : topo){
        if (!vis[u]){
            dfs2(u);
            scc.push_back(order);
            order.clear();
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < scc.size(); i++){
        int root = scc[i][0];
        for (auto v : scc[i]){
            ans[v] = root;
        }
    }

    vector<int> compress;
    for (auto &i : ans) compress.push_back(i);
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());

    cout << scc.size() << "\n";
    for (auto &i : ans) cout << lower_bound(compress.begin(), compress.end(), i) - compress.begin() + 1 << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
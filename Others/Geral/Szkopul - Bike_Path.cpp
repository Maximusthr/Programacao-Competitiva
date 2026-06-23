#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g, g_rev;
vector<vector<int>> comp, cond;
vector<bool> vis;
vector<int> topo, order;

void dfs1(int u){
    if (!vis[u]) vis[u] = true;
    for (auto v : g[u]){
        if (!vis[v]) dfs1(v);
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

vector<int> ans;
map<int, int> freq;

void dfs3(int u){
    if (!vis[u]) vis[u] = true;

    ans[u] = freq[u];

    for (auto v : cond[u]){
        if (!vis[v]) dfs3(v);
        ans[u] += ans[v];
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
        if (!vis[i]) dfs1(i);
    }

    reverse(topo.begin(), topo.end());
    vis.assign(n, false);

    vector<int> roots(n);
    for (auto u : topo){
        if (!vis[u]){
            dfs2(u);
            comp.push_back(order);
            int x = order[0];
            for (auto v : order){
                roots[v] = x;
            }
            freq[x] = order.size();
            order.clear();
        }
    }

    cond.resize(n);

    for (int i = 0; i < n; i++){
        int x = roots[i];
        for (auto v : g[i]){
            if (x != roots[v]){
                cond[x].push_back(roots[v]);
            }
        }
    }

    ans.resize(n);
    vis.assign(n, false);

    for (int i = 0; i < n; i++){
        if (!vis[roots[i]]){
            dfs3(roots[i]);
        }
    }

    for (int i = 0; i < n; i++){
        cout << ans[roots[i]] - 1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g, g_rev;
vector<vector<int>> comp, cond;
vector<int> topo, order;
vector<bool> vis;

void dfs1(int u){
    if (!vis[u]) vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v]) dfs1(v);
    }
    topo.push_back(u);
}

void dfs2(int u){
    if (!vis[u]) vis[u] = true;
    for (auto v : g_rev[u]) {
        if (!vis[v]) dfs2(v);
    }
    order.push_back(u);
}

void solve(){
    int n;

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
            order.clear();
        }
    }

    for (int i = 0; i < n; i++){
        int x = roots[i];
        for (auto u : g[i]){
            if (x != roots[u]){
                cond[x].push_back(roots[u]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m, s, e;
vector<vector<int>> g, g_rev;
vector<vector<int>> scc, cond;
vector<ll> val;
vector<bool> vis;
vector<int> topo, order;
vector<int> roots;

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

vector<bool> chegou;
vector<ll> total;

void value(int u, ll count){
    if (!vis[u]) vis[u] = true;

    total[u] += count;

    for(auto v : cond[u]){
        if (!vis[v]){
            value(v, val[roots[v]]);
        }
        if (v == roots[e] || chegou[v]){
            chegou[u] = true;
            total[u] = max(total[v] + val[roots[u]], total[u]);
        }
    }
}

void solve(){
    cin >> n >> m >> s >> e;

    s--, e--;

    vector<ll> v(n);
    for (auto &i : v) cin >> i;

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
            scc.push_back(order);
            order.clear();
        }
    }

    val.resize(n);

    roots.resize(n);

    for (int i = 0; i < scc.size(); i++){
        ll sum = 0;
        int root = scc[i][0];
        for (auto k : scc[i]){
            sum += v[k];
            roots[k] = root;
        }
        val[root] = sum;
    }

    cond.resize(n);
    for (int i = 0; i < n; i++){
        for (auto u : g[i]){
            if (roots[u] != roots[i]){
                cond[roots[i]].push_back(roots[u]);
            }
        }
    }

    // condesado de s
    // condesado de e
    vis.assign(n, false);
    chegou.resize(n);
    total.resize(n);

    value(roots[s], val[roots[s]]);

    cout << total[roots[s]] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
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

vector<bool> pode;
vector<int> roots;
vector<int> cnj;
void dfs3(int u){   
    if (!vis[u]) vis[u] = true;

    if (comp[cnj[u]].size() > 1) pode[u] = true;

    for (auto v : cond[u]){
        if (!vis[v]){
            dfs3(v);
        }
        if (pode[v]) pode[u] = true;
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
    
    reverse(topo.begin(), topo.end());
    
    
    cnj.resize(n);
    roots.resize(n);
    vis.assign(n, false);
    int c = 0;
    for (auto u : topo){
        if (!vis[u]){
            dfs2(u);
            comp.push_back(order);
            int x = order[0];
            for (auto v : order){
                roots[v] = x;
                cnj[x] = c;
            }
            order.clear();
            c++;
        }
    }

    cond.resize(n);

    for (int i = 0; i < n; i++){
        int x = roots[i];
        for (auto u : g[i]){
            if (x != roots[u]){
                cond[x].push_back(roots[u]);
            }
        }
    }

    pode.resize(n);
    vis.assign(n, false);

    for (int i = 0; i < n; i++){
        if (!vis[roots[i]]){
            dfs3(roots[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (pode[roots[i]]){
            ans += comp[cnj[roots[i]]].size();
            pode[roots[i]] = 0;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
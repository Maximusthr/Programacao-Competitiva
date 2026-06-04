#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<vector<int>> g_rev;
vector<bool> vis;

vector<int> topo;

void dfs(int u, vector<int> &order, vector<vector<int>> &gg){
    if (!vis[u]) vis[u] = true;

    for (auto v : gg[u]){
        if (!vis[v]) dfs(v, order, gg);
    }

    order.push_back(u);
}

void solve(){
    int n, m; cin >> n >> m;

    g.resize(n);
    g_rev.resize(n);
    vis.resize(n);

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g_rev[y].push_back(x);
    }

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i, topo, g);
        }
    }

    reverse(topo.begin(), topo.end());

    vis.assign(n, false);

    vector<vector<int>> scc;

    for (auto u : topo){
        if(!vis[u]){
            vector<int> comp;
            dfs(u, comp, g_rev);
            scc.push_back(comp);
        }
    }
    
    cout << scc.size() << "\n";
    for (int i = 0; i < scc.size(); i++){
        cout << scc[i].size() << " ";
        for (auto v : scc[i]){
            cout << v << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
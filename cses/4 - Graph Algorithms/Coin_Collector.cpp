#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> coins, total;
vector<vector<int>> g, g_rev;
vector<vector<int>> comp, cond;
vector<bool> vis;
vector<int> topo, order;

void dfs(int u){
    if (!vis[u]) vis[u] = true;
    for (auto v : g[u]) if (!vis[v]) dfs(v);
    topo.push_back(u);
}

void dfs2(int u){
    if (!vis[u]) vis[u] = true;
    for (auto v : g_rev[u]) if (!vis[v]) dfs2(v);
    order.push_back(u);
}

vector<ll> dp;
void dfs3(int u){
    if (!vis[u]) vis[u] = true;

    for (auto v : cond[u]){
        if (!vis[v]) dfs3(v);
        dp[u] = max(dp[u], dp[v] + total[u]);
    }
}

void solve(){
    int n, m; cin >> n >> m;

    g.resize(n), g_rev.resize(n), vis.resize(n);
    coins.resize(n);

    for (auto &i : coins) cin >> i;

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

    vector<int> roots(n);
    vector<bool> usou(n);
    total.resize(n);
    
    for (auto u : topo){
        if (!vis[u]){
            dfs2(u);
            ll sum = 0;
            comp.push_back(order);
            int x = order[0];
            usou[x] = true;
            for (auto v : order){
                roots[v] = x;
                sum += coins[v];
            }
            total[x] = sum;
            order.clear();
        }
    }

    cond.resize(n);
    vector<int> degree(n);

    for (int i = 0; i < n; i++){
        int x = roots[i];
        for (auto v : g[i]){
            if (x != roots[v]){
                cond[x].push_back(roots[v]);
                degree[roots[v]]++;
            }
        }
    }
    
    vis.assign(n, false);

    vector<int> pode;
    for(int i = 0; i < n; i++){
        int root = roots[i];
        if (usou[root] && degree[root] == 0){
            pode.push_back(root);
            usou[root] = false;
        }
    }

    dp = total;
    for (int i = 0; i < pode.size(); i++){
        if (!vis[pode[i]]){
            dfs3(pode[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
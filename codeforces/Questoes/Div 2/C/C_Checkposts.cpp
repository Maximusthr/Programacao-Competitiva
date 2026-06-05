#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

vector<vector<int>> g, g_rev, scc;
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
    int n; cin >> n;

    vector<ll> v(n);
    for (auto &i : v) cin >> i;

    int m; cin >> m;

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
    for (auto u : topo){
        if (!vis[u]){
            dfs2(u);
            scc.push_back(order);
            order.clear();
        }
    }

    ll ans = 0;
    vector<ll> eq;
    for (int i = 0; i < scc.size(); i++){
        ll menor = LINF;
        ll equal = 0;
        for (auto k : scc[i]){
            if (v[k] < menor){
                equal = 1;
                menor = v[k];
            }
            else if (v[k] == menor) equal++;
        }
        eq.push_back(equal);
        ans += menor;
    }

    ll dif = 1;
    for (int i = 0; i < eq.size(); i++){
        dif *= eq[i];
        dif %= MOD;
    }

    cout << ans << " " << dif << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
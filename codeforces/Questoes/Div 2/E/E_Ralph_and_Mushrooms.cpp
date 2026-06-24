#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;

vector<ll> prefix(MAX), geom(MAX);

vector<vector<pair<ll, ll>>> g, cond;
vector<vector<ll>> g_rev;
vector<ll> topo, order;
vector<bool> vis;
vector<ll> sum;

void dfs1(int u){
    if (!vis[u]) vis[u] = true;
    for (auto [v, w] : g[u]) {
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

vector<ll> dp;
void dfs3(int u){
    if (!vis[u]) vis[u] = true;

    dp[u] = sum[u];
    for (auto [v, w] : cond[u]){
        if (!vis[v]) dfs3(v);

        ll x = sum[u] + dp[v] + w;
        dp[u] = max(dp[u], x);
    }
}

void solve(){
    int n, m; cin >> n >> m;

    g.resize(n), g_rev.resize(n);
    vis.resize(n);

    for (int i = 0; i < m; i++){
        ll x, y, w; cin >> x >> y >> w;
        x--, y--;

        g[x].push_back({y, w});
        g_rev[y].push_back(x);
    }

    ll start; cin >> start;
    start--;

    for (int i = 0; i < n; i++){
        if (!vis[i]) dfs1(i);
    }

    reverse(topo.begin(), topo.end());
    vis.assign(n, false);

    vector<ll> roots(n);
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

    auto bb = [&](ll x) -> ll {
        ll l = 0, r = MAX;
        while(l < r){
            ll mid = l + (r - l + 1)/2;
 
            if (prefix[mid] <= x) l = mid;
            else r = mid - 1;
        }
 
        return x * (l+1) - geom[l];
    };

    sum.resize(n);
    cond.resize(n);

    for (int i = 0; i < n; i++){
        int x = roots[i];
        for (auto [u, w] : g[i]){
            if (x != roots[u]) cond[x].push_back({roots[u], w});
            else sum[x] += bb(w);
        }
    }

    vis.assign(n, false);   
    dp.resize(n); 
    dfs3(roots[start]);

    cout << dp[roots[start]] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    iota(prefix.begin(), prefix.end(), 0);
    for (int i = 1; i < MAX; i++){
        prefix[i] += prefix[i-1];
    }
    geom = prefix;
    for (int i = 1; i < MAX; i++){
        geom[i] += geom[i-1];
    }

    solve();
}
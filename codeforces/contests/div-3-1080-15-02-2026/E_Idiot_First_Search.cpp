#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

int n;
vector<vector<ll>> g;
vector<bool> vis;
vector<ll> leaf;

vector<ll> val;

void dfs(ll u){
    if (!vis[u]) vis[u] = true;

    for (auto v : g[u]){
        if (!vis[v]) {
            dfs(v);
        }
    }

    if (g[u].size() == 0){
        val[u] = 1;
    }
    else {
        val[u] += val[g[u][0]] + val[g[u][1]];
    }
}

void dfs2(ll u){
    if (!vis[u]) vis[u] = true;

    for (auto v : g[u]){
        if (!vis[v]) {
            vis[v] = true;
            val[v] = (val[v] + val[u]) % MOD;
            dfs2(v);
        }
    }
}

void solve(){
    cin >> n;
    n++;

    g.resize(n);
    g[0].push_back(1);
    for (int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        if (x != 0){
            g[i].push_back(x);
            g[i].push_back(y);
        }
        else leaf.push_back(i);
    }
    
    val.resize(n);
    vis.resize(n);

    for (int i = 0; i < leaf.size(); i++){
        val[leaf[i]] = 1;
    }
    for (int i = 1; i < n; i++){
        if (!val[i]) val[i] = 3;
    }

    dfs(1);
    vis.assign(n, false);
    dfs2(1);

    for (int i = 1; i < n; i++){
        cout << val[i] << " \n"[i== n-1];
    }

    g.clear();
    vis.clear();
    leaf.clear();
    val.clear();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
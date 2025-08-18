#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<pair<int, int>>> g;
vector<bool> vis;

int ans = 0;

void dfs(int u, int rel, int atual){
    if (!vis[u]) vis[u] = true;

    for (auto v : g[u]){
        if (!vis[v.first]){
            if (min(atual, v.second) >= rel) ans++;
            dfs(v.first, rel, min(atual, v.second));
        }

    }
}

void solve(){
    int n, q; cin >> n >> q;

    g.resize(n);
    vis.resize(n);

    for (int i = 0; i < n-1; i++){
        int x, y, z; cin >> x >> y >> z;

        x--, y--;

        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    while(q--){
        int k, v; cin >> k >> v;

        v--;

        dfs(v, k, INT32_MAX);

        cout << ans << "\n";

        ans = 0;
        vis.assign(n, false);
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    solve();
}
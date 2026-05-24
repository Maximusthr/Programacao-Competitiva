#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

struct Edge {
    ll u, v, w, c;
};

void solve(){
    ll n, q; cin >> n >> q;
    
    vector<vector<ll>> g(n);
    vector<Edge> edge(n);
    vector<ll> sz(n);
    for (int i = 0; i < n-1; i++){
        ll x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[x].push_back(i);
        g[y].push_back(i);
        edge[i] = {x, y, w, 0};
    }

    ll sum = 0;

    auto dfs = [&](auto &&self, ll u, ll p) -> void {
        sz[u] = 1;

        for (auto idx : g[u]){
            ll v = edge[idx].v;
            if (v == u) v = edge[idx].u;
            if (v == p) continue;

            self(self, v, u);

            sz[u] += sz[v];
            edge[idx].c = (sz[v] * (n - sz[v])) % MOD;
            sum += edge[idx].c * edge[idx].w;
            sum %= MOD;
        }
    };

    dfs(dfs, 0, -1);
    
    while(q--){
        ll x, w; cin >> x >> w;
        x--;

        ll old = edge[x].c * edge[x].w;
        ll nw = edge[x].c * w;

        edge[x].w = w;

        nw -= old;

        sum += nw;
        sum = ((sum % MOD) + MOD) % MOD;
        cout << sum << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
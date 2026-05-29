#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

int n, k;
vector<vector<pair<int, int>>> g;
vector<bool> vis;

ll binpow(ll a, ll b){
    ll x = 1;

    while(b > 0){
        if (b & 1) x = (x * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }

    return x % MOD;
}

ll bad = 0;
vector<ll> c;

void dfs(int u, int count, int pai){
    if (!vis[u]) vis[u] = true;

    c[u] = count;

    for (auto [v, w] : g[u]){
        if (!vis[v]) {
            if (w == 1) dfs(v, 0, v);
            else dfs(v, 1, u);

            if (w == 0) c[u] += c[v];
        }
    }

    if (u == pai) bad += binpow(c[u] + 1, k);
}

void solve(){
    cin >> n >> k;

    g.resize(n);
    vis.resize(n);
    c.resize(n);
    
    for (int i = 0; i < n-1; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    dfs(0, 0, 0);

    ll tudo = binpow(n, k);

    cout << (((tudo - bad) % MOD) + MOD) % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
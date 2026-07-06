#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

ll binpow(ll a, ll b){
    ll x = 1;
    while(b > 0){
        if (b & 1) x = x * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return x;
}

int c = 0;
void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }

    vector<int> sz(n);
    vector<bool> vis(n);

    auto dfs = [&](auto &&self, int u) -> void {
        vis[u] = true;
        sz[u] = 1;
        for (auto v : g[u]){
            if (!vis[v]) self(self, v);
            sz[u] += sz[v];
        }
    };

    for (int i = 0; i < n; i++){
        if (!vis[i]) dfs(dfs, i);
    }

    vector<ll> fat(1005);
    fat[0] = 1;
    fat[1] = 1;
    for (int i = 2; i < 1005; i++){
        fat[i] = fat[i-1] * i % MOD;
    }

    ll ans = fat[n];
    ll szz = 1;
    for (int i = 0; i < n; i++){
        szz = szz * sz[i] % MOD;
    }   

    cout << "Case " << ++c << ": ";
    cout << ans * binpow(szz, MOD - 2) % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
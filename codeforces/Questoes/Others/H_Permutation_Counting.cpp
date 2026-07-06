#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;
const int MAX = 2e6+5;

ll binpow(ll a, ll b){
    ll x = 1;
    while(b > 0){
        if (b & 1) x = x * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return x;
}

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[y].push_back(x);
    }
    
    bool ok = true;
    vector<int> color(n);
    vector<int> sz(n);
    auto dfs = [&](auto &&self, int u) -> void {
        color[u] = 1;
        sz[u] = 1;
        for (auto v : g[u]){
            if (color[v] == 0){
                self(self, v);
            }
            else if (color[v] == 1){
                ok = false;
            }
            sz[u] += sz[v];
        }
        color[u] = 2;
    };

    for (int i = 0; i < n; i++){
        if (!color[i]) dfs(dfs, i);
    }

    if (!ok){
        cout << 0 << "\n";
        return;
    }

    vector<ll> fat(MAX);
    fat[0] = 1;
    fat[1] = 1;
    for (int i = 2; i < MAX; i++){
        fat[i] = fat[i-1] * i % MOD;
    }

    ll szz = 1;
    for (int i = 0; i < n; i++){
        szz = szz * sz[i] % MOD;
    }

    cout << fat[n] * binpow(szz, MOD - 2) % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
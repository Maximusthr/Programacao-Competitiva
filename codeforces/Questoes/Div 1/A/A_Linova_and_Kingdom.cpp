#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> imp(n);
    vector<int> sz(n);
    auto dfs = [&](auto &&self, int u, int p, int prof = 1) -> void {
        sz[u] = 1;
        for (auto v : g[u]){
            if (v == p) continue;
            self(self, v, u, prof + 1);
            sz[u] += sz[v];
        }
        imp[u] = sz[u] - prof;
    };

    dfs(dfs, 0, -1);

    sort(imp.begin(), imp.end(), greater<int>());

    ll ans = 0;
    for (int i = 0; i < n-k; i++){
        ans += imp[i];
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
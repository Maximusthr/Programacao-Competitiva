#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<vector<ll>> dp(2, vector<ll> (n, 1));

    auto dfs = [&](auto &&self, int u, int p) -> void {
        for (auto v : g[u]){
            if (v == p) continue;

            self(self, v, u);

            dp[0][u] = (dp[0][u] * dp[1][v]) % MOD;
            dp[1][u] = (dp[1][u] * (dp[1][v] + dp[0][v])) % MOD;
        }
    };

    dfs(dfs, 0, -1);

    cout << (dp[0][0] + dp[1][0]) % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}

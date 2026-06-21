#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<vector<pair<int, int>>> g;

int memo[(1 << 16)][16];

int dp(int mask, int v){
    if (__builtin_popcount(mask) == n){
        for (auto u : g[v]){
            if (u.first == 0){
                return u.second;
            }
        }
        return INF;
    }

    if (memo[mask][v] != INF) return memo[mask][v];

    int ans = INF;
    for (auto [u, w] : g[v]){
        if (!(mask & (1 << u))){
            ans = min(ans, dp(mask | (1 << u), u) + w);
        }
    }

    return memo[mask][v] = ans;
}

void solve(){
    cin >> n >> m;

    g.resize(n);
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;

        g[x].push_back({y, w});
    }

    for (int i = 0; i < (1 << n); i++){
        for (int j = 0; j < n; j++){
            memo[i][j] = INF;
        }
    }

    int ans = dp(1, 0);

    if (ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
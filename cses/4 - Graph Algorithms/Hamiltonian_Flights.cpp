#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> g;
ll memo[20][(1 << 20)];

ll dp(int u, int mask){
    auto &p = memo[u][mask];

    if (u == n-1){
        return p = (mask == (1 << n) - 1);
        // return (mask == (1 << n) - 1);
    }

    if (p != -1) return p;

    int ans = 0;
    for (auto v : g[u]){
        if (!(mask & (1 << v))){
            ans += dp(v, mask | (1 << v));
            ans %= MOD;
        }
    }

    return p = ans;
}

void solve(){
    cin >> n >> m;

    g.resize(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }

    for (int i = 0; i < 20; i++){
        for (int j = 0; j < (1 << 20); j++){
            memo[i][j] = -1;
        }
    }

    cout << dp(0, 1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
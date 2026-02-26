#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
ll memo[19][(1 << 19)];
vector<vector<int>> g;

ll dp(int u, int mask){
    ll &p = memo[u][mask];
    int bits = __builtin_popcount(mask);
    int idx = __builtin_ctz(mask);

    if (p != -1) return p;

    ll ans = 0;
    for (auto v : g[u]){
        if (!(mask & (1 << v))){
            if (v > idx) ans += dp(v, mask | (1 << v));
        }
        else {
            if (bits >= 3 && v == idx){
                ans++;
            }
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
        g[y].push_back(x);
    }

    memset(memo, -1, sizeof(memo));

    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += dp(i, (1 << i));
    }
    cout << ans/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
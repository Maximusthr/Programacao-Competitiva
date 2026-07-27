#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> dp1(n), dp2(n), sum(n);
    auto dfs = [&](auto &&self, int u, int p) -> void {
        sum[u]++;
        for (auto v : g[u]){
            if (v == p) continue;

            self(self, v, u);
            sum[u] += sum[v];
        }

        if ((u != 0 && g[u].size() == 2) || (u == 0 && g[u].size() == 1)){
            int v = g[u][0];
            if (u != 0 && v == p) v = g[u][1];

            dp1[u] = max(dp1[v], dp2[v]);
            dp2[u] += sum[v];
        }
        else if ((u != 0 && g[u].size() == 3) || (u == 0  && g[u].size() == 2)){
            int v = g[u][0];
            int w = g[u][1];
            if (u != 0){
                bool foi = 0;
                for (int i = 0; i < 3; i++){
                    if (g[u][i] == p) continue;
                    if (!foi){
                        foi = true;
                        v = g[u][i];
                    }
                    else w = g[u][i];
                }
            }
            dp1[u] = max(dp1[v] + dp2[w], dp2[v] + dp1[w]);
            dp2[u] += sum[v] + sum[w];
        }
    };  

    dfs(dfs, 0, -1);

    cout << dp1[0] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
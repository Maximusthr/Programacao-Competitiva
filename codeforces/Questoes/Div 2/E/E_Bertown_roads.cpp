#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;

vector<vector<int>> g(MAX);
vector<int> dp(MAX);
vector<int> vis(MAX);

vector<pair<int, int>> ans;
bool ok = true;

void dfs(int u, int p){
    if (vis[u] == 0) vis[u] = 1;

    for (auto v : g[u]){
        if (v == p) continue;

        if (vis[v] == 1){
            ans.push_back({u, v});
            dp[u]++;
            dp[v]--;
        }
        else if (vis[v] == 0){
            ans.push_back({u, v});
            dfs(v, u);

            dp[u] += dp[v];

            if (dp[v] == 0){
                ok = false;
                return;
            }
        }
    }
    vis[u] = 2;
}

void solve(){
    int n, m; cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);

    if (ok){
        for (auto u : ans){
            cout << u.first + 1 << " " << u.second + 1 << "\n";
        }
    }
    else cout << 0 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
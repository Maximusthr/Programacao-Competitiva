vector<int> dp, vis;
vector<vector<int>> g;

void dfs(int u, int p){
    if (!vis[u]) vis[u] = 1;
    
    for (auto v : g[u]){
        if (v == p) continue;

        if (vis[v] == 1){
            // back-edge
            dp[u]++;
            dp[v]--;
        }
        else if (vis[v] == 0){
            // span-edge
            dfs(v, u);

            dp[u] += dp[v];

            if (dp[v] == 0){
                // ponte {u, v}
            }
        }
    }
    vis[u] = 2;
}
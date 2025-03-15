#include <bits/stdc++.h>

using namespace std;

int n, m; 
const int MAX = 11;
vector<vector<pair<int, long long>>> g(MAX);
vector<bool> vis(MAX);

long long ans = LLONG_MAX;
void dfs(int x, long long z){
    if (x == n-1){
        ans = min(ans , z);
        return;
    }
    vis[x] = true;
    
    for (auto [u, v] : g[x]){
        if (!vis[u]){
            dfs(u, (z ^ v));
        }
    }

    vis[x] = false; // unblocking to allow new paths 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--;
        y--;
        long long z; cin >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
     
    dfs(0, 0);
    
    cout << ans << "\n";
}

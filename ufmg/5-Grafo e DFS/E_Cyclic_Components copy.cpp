#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 1;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

bool ok;
void dfs(int u){
    vis[u] = true;

    if (g[u].size() != 2){
        ok = false;
    }
    
    for (auto w : g[u]){
        if (!vis[w]){
            dfs(w);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int x, y; cin >> x >> y;

    for (int i = 0; i < y; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < x; i++){
        if (!vis[i]){
            ok = true;
            dfs(i);
            if (ok) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

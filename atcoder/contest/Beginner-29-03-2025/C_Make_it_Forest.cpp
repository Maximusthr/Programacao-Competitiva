#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+1;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

int ans = 0;
void dfs(int v, int parent){
    if (!vis[v]) vis[v] = true;

    for (auto w : g[v]){
        if (!vis[w]){
            dfs(w, v);
        }
        else if (w != parent) ans++;
    }
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++){
        if (!vis[i]) {
            dfs(i, -1);
        }
    }


    cout << ans/2 << "\n";

}
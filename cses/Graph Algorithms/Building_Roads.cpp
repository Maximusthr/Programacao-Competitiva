#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+1;

vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

void dfs(int u){
    if (!vis[u]) vis[u] = true;

    for (auto w : g[u]){
        if (!vis[w]) {
            vis[w] = true;
            dfs(w);
        }
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

    vector<int> index;
    int sum = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i);
            sum++;
            index.push_back(i+1);
        }
    }

    if (sum >= 2){
        cout << sum-1 << "\n";
        for (int i = 1; i < (int)index.size(); i++){
            cout << index[i-1] << " " << index[i] << "\n";
        }
    }
    else cout << 0 << "\n";
}

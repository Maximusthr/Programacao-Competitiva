#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+1;

// vector<vector<vector<int>>> g(MAX, vector<vector<int>> (2));
vector<int> g[MAX][2];
vector<bool> vis(MAX);

void dfs(int u, int id){
    if (!vis[u]) vis[u] = true;

    for (auto v : g[u][id]){
        if (!vis[v]){
            dfs(v, id);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m; cin >> n >> m;

    for (int i = 0 ; i < m; i++){
        int x, y; cin >> x >> y;

        x--, y--;

        g[x][0].push_back(y);
        g[y][1].push_back(x);
    }

    dfs(0, 0);
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            cout << "NO" << "\n";
            cout << 1 << " " << i+1 << "\n";
            return 0;
        }
    }

    vis.assign(MAX, false);

    dfs(0, 1);
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            cout << "NO" << "\n";
            cout << i+1 << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES" << "\n";
}
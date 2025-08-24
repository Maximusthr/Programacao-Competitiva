#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<bool> vis;

ll comp = 0;
ll edges = 0;

void dfs(int u){

    if (!vis[u]) vis[u] = true;

    edges += g[u].size();
    comp++;

    for (auto v : g[u]){
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;
    g.resize(n);
    vis.resize(n);

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i);

            edges /= 2;

            if (edges != comp*(comp-1)/2) {
                cout << "NO" << "\n";
                return;
            }

            comp = 0;
            edges = 0;
        }
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}
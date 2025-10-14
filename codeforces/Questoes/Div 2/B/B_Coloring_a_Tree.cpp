#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<int> color;
vector<int> atual;
vector<bool> vis;

int ans = 1;

void dfs(int u, int c){
    if (!vis[u]) vis[u] = true;

    atual[u] = c;

    if (atual[u] != color[u]){
        c = color[u];
        ans++;
    }

    for (auto v : g[u]){
        if (!vis[v]){
            dfs(v, c);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    g.resize(n);
    vis.resize(n);
    color.resize(n);
    atual.resize(n);

    for (int i = 1; i < n; i++){
        int x; cin >> x;

        x--;

        g[x].push_back(i);
        g[i].push_back(x);
    }

    for (auto &i : color) cin >> i;

    dfs(0, color[0]);

    cout << ans << "\n";
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<vector<int>> g;
vector<bool> vis;
vector<int> pai;
int cycle_st = -1, cycle_end = -1;
bool ok = false;
void dfs(int u, int p){
    vis[u] = true;

    for (auto v : g[u]){
        if (v == p) continue;

        if (vis[v]){
            cycle_st = u;
            cycle_end = v;
            ok = true;
            return;
        }

        pai[v] = u;
        dfs(v, u);
    }
}

void solve(){
    cin >> n >> m;

    g.resize(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vis.resize(n);
    pai.resize(n);

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i, -1);
            if (ok) break;
        }
    }
    
    if (cycle_end == -1){
        cout << "IMPOSSIBLE" << "\n";
    }
    else {
        vector<int> path;
        path.push_back(cycle_st);

        for (int u = cycle_end; u != cycle_st; u = pai[u]){
            path.push_back(u);
        }
        path.push_back(cycle_st);

        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for (auto &i : path) cout << i + 1 << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
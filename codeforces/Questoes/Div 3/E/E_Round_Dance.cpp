#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vector<set<int>> g;
vector<bool> vis;

bool ok = false;

void dfs(int u){
    if (!vis[u]) vis[u] = true;

    if (g[u].size() == 1) ok = true;

    for (auto v : g[u]){
        if (!vis[v]){
            dfs(v);
        }
    }
}

void solve(){
    cin >> n;

    g.resize(n);
    vis.resize(n);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        x--;

        g[i].insert(x);
        g[x].insert(i);
    }

    int ciclos = 0, unico = 0;

    for (int i = 0; i < n; i++){
        ok = false;
        if (!vis[i]){
            dfs(i);

            if (ok) unico++;
            else ciclos++;
        }
    }

    cout << ciclos + min(unico, 1) << " " << ciclos + unico << "\n";

    g.clear();
    vis.clear();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
// https://dmoj.ca/problem/acsl1p4

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 25;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

set<int> ans;
void dfs(int u, int p){
    if (!vis[u]) vis[u] = true;

    for (auto &v : g[u]){
        if (!vis[v]){
            dfs(v, u);
        }
        else if (p != -1 && v != p){
            if (g[v].size() == 0) continue;
            ans.insert(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    for (int i = 0; i < k; i++){
        int x, y, a, b; cin >> x >> y >> a >> b;
        x--, y--;
        if (a > b) g[x].push_back(y);
        else g[y].push_back(x);
    }

    for (int i = 0; i < n; i++){
        if (!vis[i]) dfs(i, -1);
        vis.assign(MAX, false);
    }

    cout << ans.size() << "\n";
}
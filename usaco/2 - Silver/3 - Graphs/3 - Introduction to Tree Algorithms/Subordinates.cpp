#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<bool> vis;

vector<int> subord;

void dfs(int u){
    if (!vis[u]) vis[u] = true;

    subord[u] = g[u].size();

    for (auto v : g[u]){
        if (!vis[v]) {
            vis[v] = true;
            dfs(v);
            subord[u] += subord[v];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    g.resize(n);
    vis.resize(n);
    subord.resize(n);

    for (int i = 0; i < n-1; i++){
        int x; cin >> x;
        x--;
        g[i+1].push_back(x);
        g[x].push_back(i+1);
    }

    dfs(0);

    for (int i = 0; i < n; i++){
        cout << subord[i] / 2 << " \n"[i==n-1];
    }

}
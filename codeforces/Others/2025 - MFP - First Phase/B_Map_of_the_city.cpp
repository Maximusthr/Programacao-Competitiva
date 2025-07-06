#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+1;

vector<vector<int>> g(MAX);
vector<int> vis(MAX);

int ciclos = 0;
void dfs(int u, int p){
    if (!vis[u]) vis[u] = true;

    for (auto v: g[u]){
        if (!vis[v]){
            dfs(v, u);
        }
        else if (v != p){
            ciclos++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int comp = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i, -1);
            comp++;
        }
    }
    if (ciclos == 0 && comp <= 1){
        cout << "BOM" << "\n";
    }
    else cout << "RUIM " << ciclos/2 << " " << comp-1 << "\n";
}
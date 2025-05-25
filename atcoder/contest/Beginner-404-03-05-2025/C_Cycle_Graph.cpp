#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+1;

vector<int> g[MAX];
vector<int> vis(MAX);

bool ok;
void dfs(int u){
    if (!vis[u]) vis[u] = true;
    
    if (g[u].size() != 2){
        ok = false;
    }

    for (auto v : g[u]){
        if (!vis[v]) {
            dfs(v);
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

    int aux = 0;
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            ok = true;
            aux++;
            if (aux == 2){
                ok = false;
                break;
            }
            dfs(i);
        }
    }

    cout << (ok ? "Yes" : "No") << "\n";
}

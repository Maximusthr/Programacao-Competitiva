#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+1;
vector<int> g[MAX];
vector<bool> vis(MAX);

vector<int> valores;

void dfs(int u){
    vis[u] = true;

    for (auto v : g[u]){
        if (!vis[v]){
            dfs(v);
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

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i);
            valores.push_back(i);
        }
    }

    cout << valores.size()-1 << "\n";
    if (valores.size()-1 == 0) return 0;

    for (int i = 0; i < valores.size()-1; i++){
        cout << valores[i] + 1 << " " << valores[i+1] + 1 << "\n";
    }
    cout << "\n";
}
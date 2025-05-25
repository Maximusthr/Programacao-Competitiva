#include <bits/stdc++.h>

using namespace std;


int n, m;
const int MAX = 11;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);
vector<bitset<4>> valores;


void dfs(int u){
    vis[u] = true;

    for (auto w : g[u]){
        if (!vis[w]){
            valores.push_back(g[u][w]);
            dfs(w);
        }
    }
}

int main(){
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        g[x][y] = z;
    }

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i);
        }
    }

    unsigned long long maior_valor = 0;

    for (int i = 1; i < (int)valores.size(); i++){
        bitset<4> c = valores[i] ^ valores[i-1];
        maior_valor = max(maior_valor, c.to_ullong());
    }

    cout << maior_valor << "\n";
}

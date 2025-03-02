// DFS É UMA FUNÇÃO, ENTÃO É NECESSÁRIO VARIÁVEIS GLOBAIS

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+10; // número máximo de vértices.

vector<vector<int>> g(MAX);
vector<bool> vis(MAX); // se o vizinho já foi visitado ou não

void dfs (int v){
    vis[v] = true;

    for (auto w : g[v]) {
        if (!vis[w]) 
            dfs(w);
    }
}


int main(){

}
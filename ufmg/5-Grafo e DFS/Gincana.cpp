// Using BFS

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3+1;

vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

void bfs(int v){
    queue<int> fila;
    fila.push(v);
    
    while(!fila.empty()){
        int aux = fila.front();
        vis[aux] = true;
        fila.pop();

        for (auto w : g[aux]){
            if (!vis[w]){
                vis[w] = true;
                fila.push(w);
            }
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

    int res = 0;
    
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            bfs(i);
            res++;
        }
    }

    cout << res << "\n";
}

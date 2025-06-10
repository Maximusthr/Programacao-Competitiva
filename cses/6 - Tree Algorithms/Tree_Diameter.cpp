#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+10;
vector<vector<int>> g(MAX);
vector<int> vis(MAX, -1);

void dfs(int v){
    for (auto w : g[v]){
        if (vis[w] == -1){
            vis[w] = vis[v] + 1;
            dfs(w);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    
    for (int i = 0; i < t-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    vis[0] = 0;
    dfs(0);

    int pos = -1, maior = -1;
    for (int i = 0; i < t; i++){
        if (maior < vis[i]) {
            maior = vis[i];
            pos = i;
        }
    }

    vis.assign(MAX, -1);

    vis[pos] = 0;
    dfs(pos);
    int diametro = 0;
    for (int i = 0; i < t; i++){
        diametro = max(diametro, vis[i]);
    }

    cout << diametro << "\n";
}

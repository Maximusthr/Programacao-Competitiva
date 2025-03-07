#include <bits/stdc++.h>

using namespace std;

int n, m;

const int MAX = 4955;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);
vector<pair<int, int>> nodes_edges;

int edges;
int nodes;

void dfs(int v){
    vis[v] = true;
    edges += g[v].size();
    nodes++;

    for (auto w : g[v]){
        if (!vis[w]){
            dfs(w);
        }
    }

    //return edges;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    edges = 0, nodes = 0;
    
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i);
            nodes_edges.push_back({nodes, edges/2});
            nodes = 0;
            edges = 0;
        }
    }   

    bool ok = true;
    for (int i = 0; i < (int)nodes_edges.size(); i++){
        if (nodes_edges[i].first > nodes_edges[i].second) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "FHTAGN!" : "NO") << "\n";

}

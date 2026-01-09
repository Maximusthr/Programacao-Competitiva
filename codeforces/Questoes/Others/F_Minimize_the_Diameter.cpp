#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void dfs(int u, vector<int> &dist, vector<vector<int>> &g){
    for (auto v : g[u]){
        if (dist[v] == -1){
            dist[v] = dist[u] + 1;
            dfs(v, dist, g);
        }
    }
}

// um dia eu refaço =)

void solve(){
    int n; cin >> n;

    vector<vector<int>> g1(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g1[x].push_back(y);
        g1[y].push_back(x);
    }
    
    vector<int> dist1(n, -1);
    dist1[0] = 0;
    dfs(0, dist1, g1);
    pair<int, int> node = {-1, -1};
    for (int i = 0; i < n; i++){
        if (dist1[i] > node.second){
            node.first = i;
            node.second = dist1[i];
        }
    }
    
    dist1.assign(n, -1);
    dist1[node.first] = 0;
    
    dfs(node.first, dist1, g1);
    node = {-1, -1};
    for (int i = 0; i < n; i++){
        if (dist1[i] > node.second){
            node.first = i;
            node.second = dist1[i];
        }
    }

    
    int m; cin >> m;
    vector<vector<int>> g2(m);
    vector<int> dist2(m, -1);
    
    for (int i = 0; i < m-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g2[x].push_back(y);
        g2[y].push_back(x);
    }
    
    dist2[0] = 0;
    dfs(0, dist2, g2);
    pair<int, int> node2 = {-1, -1};
    for (int i = 0; i < m; i++){
        if (dist2[i] > node2.second){
            node2.first = i;
            node2.second = dist2[i];
        }
    }

    dist2.assign(m, -1);
    dist2[node2.first] = 0;

    dfs(node2.first, dist2, g2);
    node2 = {-1, -1};
    for (int i = 0; i < m; i++){
        if (dist2[i] > node2.second){
            node2.first = i;
            node2.second = dist2[i];
        }
    }

    // unir os pontos medios das duas arvores
    array<pair<int, int>, 2> nodes;

    int dist_media = node.second/2;
    for (int i = 0; i < n; i++){
        if (dist1[i] == dist_media){
            nodes[0] = {i, dist1[i]};
            break;
        }
    }

    dist_media = node2.second/2;
    for (int i = 0; i < m; i++){
        if (dist2[i] == dist_media){
            nodes[1] = {i, dist2[i]};
            break;
        }
    }

    g1.resize(n+m);

    g1[nodes[0].first].push_back(nodes[1].first+n);
    g1[nodes[1].first+n].push_back(nodes[0].first);
    
    for (int i = 0; i < m; i++){
        for (auto u : g2[i]){
            g1[i+n].push_back(u+n);
        }
    }

    // uno todas as árvores

    dist1.assign(n+m, -1);

    dist1[0] = 0;
    dfs(0, dist1, g1);
    node = {-1, -1};
    for (int i = 0; i < (n+m); i++){
        if (dist1[i] > node.second){
            node.first = i;
            node.second = dist1[i];
        }
    }

    dist1.assign(n+m, -1);
    dist1[node.first] = 0;

    dfs(node.first, dist1, g1);
    node = {-1, -1};
    for (int i = 0; i < n+m; i++){
        if (dist1[i] > node.second){
            node.first = i;
            node.second = dist1[i];
        }
    }

    cout << node.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<vector<int>> g(MAX);
    vector<int> dist(MAX, -1);

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;

        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> pai(MAX, -1);

    queue<int> fila;
    fila.push(0);
    dist[0] = 0;
    while(!fila.empty()){
        int u = fila.front();

        fila.pop();

        for (auto v : g[u]){
            if (dist[v] == -1){
                dist[v] = dist[u] + 1;
                pai[v] = u;
                fila.push(v);
            }
        }
    }

    if (pai[n-1] == -1){
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }

    vector<int> path;
    for (int i = n-1; i != -1; i = pai[i]){
        path.push_back(i+1);
    }

    reverse(path.begin(), path.end());

    cout << dist[n-1] + 1 << "\n";
    for (auto &i : path) cout << i << " ";
    cout << "\n";
}   
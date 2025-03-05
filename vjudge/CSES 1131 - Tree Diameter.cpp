#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 1;
vector<vector<int>> g(MAX);
vector<int> dist(MAX, -1);

void dfs(int v){
    for (auto w : g[v]){
        if (dist[w] == -1){
            dist[w] = dist[v] + 1;
            dfs(w);
        }
    }
}

int main(){
    int n; cin >> n;
    
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dist[0] = 0;
    dfs(0);
    int maior = -1, pos = -1;
    for (int i = 0; i < n; i++){
        if (maior < dist[i]) {
            maior = dist[i];
            pos = i;
        }
    }

    dist.assign(MAX, -1);
    dist[pos] = 0;
    dfs(pos);
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, dist[i]);
    }

    cout << ans << "\n";
}

#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
vector<vector<int>> g(MAX);
vector<int> vis(MAX);

int ans = 0;
void dfs(int v, int p){
    vis[v] = true;

    for (auto w : g[v]){
        if (!vis[w]){
            dfs(w, v);
        }
        else if (w != p) ans++;
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
            aux++;
            if (aux == 2) {
                ans = -1;
                break;
            }
            dfs(i, -1);
        }
    }

    if (ans/2 == 1) cout << "FHTAGN!" << "\n";
    else cout << "NO" << "\n";

}

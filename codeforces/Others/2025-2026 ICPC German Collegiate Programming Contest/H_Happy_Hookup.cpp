#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<bool> vis(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        
        x--, y--;
        g[x].push_back(y);
    }

    int A, B; cin >> A >> B;
    A--, B--;
    
    vector<bool> vis2(n);
    
    auto dfs = [&](auto &&self, int u, vector<bool> &visit) -> void {
        if (!visit[u]) visit[u] = true;

        for (auto v : g[u]){
            if (!visit[v]) {
                self(self, v, visit);
            }
        }
    };

    dfs(dfs, A, vis);
    dfs(dfs, B, vis2);

    for (int i = 0; i < n; i++){
        if (vis[i] && vis2[i]){
            cout << "yes" << "\n";
            cout << i + 1 << "\n";
            return 0;
        }
    }

    cout << "no" << "\n";
}
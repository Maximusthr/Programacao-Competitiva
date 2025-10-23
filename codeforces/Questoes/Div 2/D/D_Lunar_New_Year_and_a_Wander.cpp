#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);
    vector<bool> vis(n);

    vector<pair<int, int>> pares;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> ans;
    
    auto bfs = [&](auto self, int u) -> void {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(0);
        while (!pq.empty()){
            int u = pq.top();
            pq.pop();

            if (!vis[u]) {
                vis[u] = true;
                ans.push_back(u);
            }
            else continue;

            for (auto v : g[u]){
                if (!vis[v]){
                    pq.push(v);
                }
            }
        }
    };

    bfs(bfs, 0);

    for (int i = 0; i < n; i++){
        cout << ans[i] + 1 << " \n"[i == n-1];
    }
}
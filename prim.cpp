#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    vector<int> chave(n, INF);
    vector<int> pai(n);
    vector<bool> vis(n);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    
    chave[0] = 0;
    ll ans = 0;
    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        
        vis[u] = true;
        ans += w;

        for (auto [v, W] : g[u]){
            if (!vis[v]){
                if (W < chave[v]){
                    chave[v] = W;
                    pai[v] = u;
                    pq.push({W, v});
                }
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}

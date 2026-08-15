#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<pair<ll, ll>>> g(n);
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w});
    }

    vector<ll> qtd(n), min_p(n), max_p(n), dist(n, LINF);

    dist[0] = 0;
    qtd[0] = 1;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        ll w = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (w > dist[u]) continue;

        for (auto [v, W] : g[u]){
            if (dist[v] > dist[u] + W){
                dist[v] = dist[u] + W;
                qtd[v] = qtd[u];
                min_p[v] = min_p[u] + 1;
                max_p[v] = max_p[u] + 1;

                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + W){
                qtd[v] = (qtd[u] + qtd[v]) % MOD;
                min_p[v] = min(min_p[u] + 1, min_p[v]);
                max_p[v] = max(max_p[u] + 1, max_p[v]);
            }
        }
    }
    
    cout << dist[n-1] << " " << qtd[n-1] << " " << min_p[n-1] << " " << max_p[n-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}

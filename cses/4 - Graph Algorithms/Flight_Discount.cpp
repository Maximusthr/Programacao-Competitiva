#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<pair<ll, ll>>> g(n);
    for (int i = 0; i < m; i++){
        ll x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w});
    }

    vector<vector<ll>> dist(n, vector<ll>(2, LINF));

    struct P {
        ll w, x, d;
        bool operator>(P const &p) const {
            return w > p.w;
        };
    };

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while(!pq.empty()){
        auto [w, u, d] = pq.top();
        pq.pop();
        if (w > dist[u][d]) continue;

        for (auto [v, W] : g[u]){
            if (d == 0){
                // posso usar o ticket
                if (dist[u][d] + W/2 < dist[v][d^1]){
                    dist[v][d^1] = dist[u][d] + W/2;
                    pq.push({dist[v][d^1], v, d^1});
                }
            }
            // nao quero usar | ja estou usando
            if (dist[u][d] + W < dist[v][d]){
                dist[v][d] = dist[u][d] + W;
                pq.push({dist[v][d], v, d});
            }
        }
    }

    cout << min(dist[n-1][0], dist[n-1][1]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
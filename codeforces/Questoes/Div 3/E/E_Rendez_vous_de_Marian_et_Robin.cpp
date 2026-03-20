#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, h; cin >> n >> m >> h;

    vector<bool> horses(n);
    for (int i = 0; i < h; i++){
        int x; cin >> x;
        x--;
        horses[x] = true;
    }

    vector<vector<pair<int, ll>>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        ll w; cin >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    vector<vector<ll>> dist(n, vector<ll> (2, LINF)), dist1(n, vector<ll> (2, LINF));

    // dist representa 1
    // dist1 representa n

    struct P{
        ll w, x, h;

        bool operator>(P const &p) const {
            return w > p.w;
        };
    };

    auto dijkstra = [&](vector<vector<ll>> &d, int u) -> void {
        priority_queue<P, vector<P>, greater<P>> pq;

        if (horses[u]){
            d[u][1] = 0;
            pq.push({0, u, 0});
        }
        else {
            d[u][0] = 0;
            pq.push({0, u, -1});
        }

        while (!pq.empty()){
            auto [w, u, hor] = pq.top();
            pq.pop();
    
            if (hor != -1){
                if (w > d[u][1]) continue;
            }
            else {
                if (w > d[u][0]) continue;
            }
    
            for (auto [v, W] : g[u]){
                // no ponto v eu posso ter um cavalo disponvivel
                // mas se meu hor é -1, entao eu devo continuar sem fazer nada
                // se hor != -1, entao eu passo o peso divido por 2
    
                if (hor != -1){
                    if (d[u][1] + W/2 < d[v][1]){
                        d[v][1] = d[u][1] + W/2;
                        pq.push({d[v][1], v, hor});
                    }
                }
                else {
                    if (d[u][0] + W < d[v][0]){
                        d[v][0] = d[u][0] + W;
                        pq.push({d[v][0], v, hor});
                    }
                    // mas e se na cidade tiver um cavalo? entao eu posso passar o cavalo para as proximas iterações
                    if (horses[v] && hor == -1){
                        if (d[u][0] + W < d[v][1]){
                            d[v][1] = d[u][0] + W;
                            pq.push({d[v][1], v, v});
                        }
                    }
                }
            }
        }
    };

    dijkstra(dist, 0);

    if (dist[n-1][0] == LINF && dist[n-1][1] == LINF){
        cout << -1 << "\n";
        return;
    }

    dijkstra(dist1, n-1);

    ll ans = LINF;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            ans = min(max(dist[i][j], dist1[i][j]), ans);
            ans = min(max(dist[i][j^1], dist1[i][j]), ans);
            ans = min(max(dist[i][j^1], dist1[i][j^1]), ans);
            ans = min(max(dist[i][j], dist1[i][j^1]), ans);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
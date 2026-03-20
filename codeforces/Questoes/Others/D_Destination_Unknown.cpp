#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct P {
    int w, u, tipo;

    bool operator>(P const &p) const {
        return w > p.w;
    };
};

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<bool> start(n);
    int s, gg, h; cin >> s >> gg >> h;
    s--, gg--, h--;
    start[gg] = 1;
    start[h] = 1;

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    vector<bool> local(n);
    for (int i = 0; i < k; i++){
        int x; cin >> x;
        x--;
        local[x] = 1;
    }

    // [0] representa que nao veio da aresta "boa"
    // [1] representa que a aresta boa ja foi percorrida

    vector<vector<int>> dist(n, vector<int> (2, INF));
    dist[s][0] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s, 0});
    while(!pq.empty()){
        auto [w, u, tipo] = pq.top();
        pq.pop();

        if (w > dist[u][tipo]) continue;

        for (auto [v, W] : g[u]){
            // primeiro eu vejo se a aresta foi percorrida, pq dai eu ja acho a resposta
            if (tipo){
                if (dist[u][tipo] + W < dist[v][tipo]){
                    dist[v][tipo] = dist[u][tipo] + W;
                    pq.push({dist[v][tipo], v, tipo});
                }
            }
            else {
                if (start[u] && start[v]){
                    // achei a aresta que preciso obrigatoriamente caminhar sobre
                    if (dist[u][tipo] + W < dist[v][tipo^1]){
                        dist[v][tipo^1] = dist[u][tipo] + W;
                        pq.push({dist[v][tipo^1], v, tipo^1});
                    }
                }
                else {
                    if (dist[u][tipo] + W < dist[v][tipo]){
                        dist[v][tipo] = dist[u][tipo] + W;
                        pq.push({dist[v][tipo], v, tipo});
                    }
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (local[i]){
            if (dist[i][1] <= dist[i][0] && dist[i][1] != INF) ans.push_back(i+1);
        }
    }

    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
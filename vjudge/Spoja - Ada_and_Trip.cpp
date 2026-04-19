#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, q; cin >> n >> m >> q;

    struct P {
        ll v, w;

        bool operator>(P const p) const {
            return w > p.w;
        };
    };

    vector<vector<P>> g(n+1);
    for (int i = 0; i < m; i++){
        ll x, y, w; cin >> x >> y >> w;
        if (x == y) continue;
        
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    map<int, pair<int, int>> city;

    while(q--){
        int x; cin >> x;

        if (city.count(x)){
            cout << city[x].first << " " << city[x].second << "\n";
            continue;
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> dist(n+1, INF);
        dist[x] = 0;
        pq.push({x, dist[x]});

        while(!pq.empty()){
            int d = pq.top().w;
            int u = pq.top().v;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto [v, w] : g[u]){
                if (dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;

                    pq.push({v, dist[v]});
                }
            }
        }

        pair<int, int> maior = {0, 0};
        for (int i = 0; i <= n; i++){
            if (dist[i] == INF) continue;

            if (dist[i] == maior.first) maior.second++;
            else if (dist[i] > maior.first){
                maior = {dist[i], 1};
            }
        }

        city[x] = maior;

        cout << city[x].first << " " << city[x].second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
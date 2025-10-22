// DIJKSTRA

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> g(n);
    for (int i = 0; i < m; i++){
        int x, y, t; cin >> x >> y >> t;
        x--, y--;
        g[x].push_back({y, t});
        g[y].push_back({x, t});
    }

    vector<int> p(k);
    for (int i = 0; i < k; i++){
        cin >> p[i];
        p[i]--;
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(n, LINF);

    for (int i = 0; i < k; i++){
        dist[p[i]] = 0;
        pq.push({0, p[i]});
    }

    while (!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if (w > dist[u]) continue;

        for (auto [v, W] : g[u]){
            if (dist[u] + 2*W < dist[v]){
                dist[v] = dist[u] + 2*W;
                pq.push({dist[v], v});
            }
        }
    }

    auto ok = [&](ll mid) -> bool {
        vector<ll> d(n, LINF);
        d[0] = -mid;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

        q.push({d[0], 0});

        while (!q.empty()){
            auto [w, u] = q.top();
            q.pop();

            if (w > d[u]) continue;

            for (auto [v, W] : g[u]){
                if (d[u] + W < d[v] && d[u] + W <= dist[v]){
                    d[v] = d[u] + W;
                    q.push({d[v], v});
                }
            }
        }

        return (d[n-1] != LINF);
    };

    ll l = 0, r = 2e9;
    while(l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid + 1;
    }
    cout << l << "\n";
}
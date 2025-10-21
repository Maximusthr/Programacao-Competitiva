#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<vector<pair<int, ll>>> g(n);
    
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;  

    vector<ll> dist(n, LINF);

    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [z, u] = pq.top();
        pq.pop();

        if (z != dist[u]) continue;

        for (auto [v, w] : g[u]){
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << dist[i] << " \n"[i==n-1];
    }
}

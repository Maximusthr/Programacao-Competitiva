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
        g[y].push_back({x, w});
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    vector<ll> dist(n, LINF);
    vector<int> pai(n, -1);
    dist[0] = 0;

    pq.push({0, 0});
    while(!pq.empty()){
        auto [z, v] = pq.top();
        pq.pop();

        if (z > dist[v]) continue;

        for (auto [u, w] : g[v]){
            if (dist[v] + w < dist[u]){
                dist[u] = dist[v] + w;
                pai[u] = v;
                
                pq.push({w, u});
            }
        }
    }

    if (pai[n-1] == -1){
        cout << -1 << "\n";
        return 0;
    }
    
    vector<int> path;
    for (int u = n-1; u != -1; u = pai[u]){
        path.push_back(u);
    }

    reverse(path.begin(), path.end());
    
    for(int i = 0; i < path.size(); i++){
        cout << path[i] + 1 << " \n"[i == path.size()-1];
    }
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<pair<int, int>>> g(n);

    int aux = 0;
    map<string, int> city;

    for (int i = 0; i < n; i++){
        string s; cin >> s;
        city[s] = aux++;
    
        int m; cin >> m;

        for (int j = 0; j < m; j++){
            int y, w; cin >> y >> w;
            y--;
            g[city[s]].push_back({y, w});
        }
    }

    int q; cin >> q;
    while(q--){
        
        string s, en; cin >> s >> en;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INF);

        dist[city[s]] = 0;
        pq.push({0, city[s]});

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d > dist[u]) continue;

            for (auto [v, w] : g[u]){
                if (w + dist[u] >= dist[v]) continue;

                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }

        cout << dist[city[en]] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
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
        g[y].push_back({x, w});
    }
    
    vector<ll> slow(n);
    for (auto &i : slow) cin >> i;

    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    vector<vector<ll>> dist(n, vector<ll> (n, LINF));
    dist[0][0] = 0;
    
    pq.push({dist[0][0], 0, 0});
    while(!pq.empty()){
        auto [w, u, S] = pq.top();
        pq.pop();

        if (slow[S] > slow[u]) S = u;

        if (w > dist[u][S]) continue;
        dist[u][S] = w;

        for (auto [v, W] : g[u]){
            if (dist[u][S] + W * slow[S] < dist[v][S]){
                dist[v][S] = dist[u][S] + W * slow[S];
                pq.push({dist[v][S], v, S});
            }
        }
    }

    cout << *min_element(dist[n-1].begin(), dist[n-1].end()) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
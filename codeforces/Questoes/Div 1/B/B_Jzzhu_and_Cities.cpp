#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Edges {
    ll u, w; 
    bool trem;

    bool operator<(const Edges &P) const {
        return w > P.w;
    };
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<Edges>> g;
    vector<ll> dist;
    g.resize(n);
    dist.resize(n, LINF);
    
    for (int i = 0; i < m; i++){
        ll x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w, false});
        g[y].push_back({x, w, false});
    }

    for (int i = 0; i < k; i++){
        ll v, w; cin >> v >> w;
        v--;
        g[0].push_back({v, w, true});
        g[v].push_back({0, w, true});
    }
    
    vector<bool> tr(n);

    priority_queue<Edges> pq;
    dist[0] = 0;

    pq.push({0, 0, 0});
    while(!pq.empty()){
        ll u = pq.top().u;
        ll w = pq.top().w;
        bool trem = pq.top().trem;
        pq.pop();
        
        if (w > dist[u]) continue;

        
        for (auto [v, W, tt] : g[u]){
            if (dist[u] + W < dist[v]){
                dist[v] = dist[u] + W;
                tr[v] = tt;
                pq.push({v, dist[v], tt});
            }
            else if (dist[u] + W == dist[v]){
                if (tr[v] && !tt) tr[v] = false;
            }
        }
    }

    int usou = 0;
    for (int i = 0; i < n; i++){
        usou += tr[i];
    }

    cout << k - usou << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
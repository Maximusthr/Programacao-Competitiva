#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct P {
    int u, w, q;

    bool operator>(P const p) const {
        return w > p.w;
    };
};

void solve(){
    int n, m, l, s, t; cin >> n >> m >> l >> s >> t;

    vector<set<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[x].insert({y, w});
    }

    vector<bool> vis(n);
    
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0, 0});

    while(!pq.empty()){
        int u = pq.top().u;
        int w = pq.top().w;
        int qtd = pq.top().q;
        pq.pop();

        if (qtd == l && w >= s && w <= t){
            vis[u] = true;
            continue;
        }
        if (w > t || qtd > l) continue;

        for (auto [v, W] : g[u]){
            pq.push({v, W + w, qtd + 1});
        }
    }

    for (int i = 0; i < n; i++){
        if (vis[i]) cout << i+1 << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct P {
    ll u, w;

    bool operator>(P const p) const {
        return w > p.w;
    }
};

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<vector<P>> g(n);
    vector<vector<ll>> dist(n, vector<ll> (k, LINF));

    for (int i = 0; i < m; i++){
        ll x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    dist[0][0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        ll u = pq.top().u;
        ll w = pq.top().w;

        pq.pop();

        bool flag = false;
        for (int i = 0; i < k; i++){
            if (w > dist[u][i]) continue;
            else {
                flag = true;
                break;
            }
        }

        if (!flag) continue;

        for (auto [v, W] : g[u]){
            for (int i = 0; i < k; i++){
                if (w + W < dist[v][i]){
                    dist[v][i] = w + W;
                    pq.push({v, dist[v][i]});
                    sort(dist[v].begin(), dist[v].end(), greater<ll>());
                    break;
                }
            }   
        }
    }

    vector<ll> ans;
    for (int i = 0; i < k; i++){
        ans.push_back(dist[n-1][i]);
    }

    sort(ans.begin(), ans.end());

    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
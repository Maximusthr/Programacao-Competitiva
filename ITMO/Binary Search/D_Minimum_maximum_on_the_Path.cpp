#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, d; cin >> n >> m >> d;

    vector<vector<pair<int, int>>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({y, w});
        deg[y]++;
    }

    vector<int> topo;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        topo.push_back(u);
        q.pop();

        for (auto [v, w] : g[u]){
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
    
    vector<int> pai(n);
    
    auto ok = [&](int mid) -> bool {
        vector<int> dp(n, INF);
        dp[0] = 0;
        for (auto u : topo){
            for (auto [v, w] : g[u]){
                if (w <= mid){
                    if (dp[u] + 1 < dp[v]){
                        dp[v] = dp[u] + 1;
                        pai[v] = u;
                    }
                    dp[v] = min(dp[v], dp[u] + 1);
                }
            }
        }

        return (dp[n-1] <= d);
    };

    int l = 0, r = INF;
    while(l < r){
        int mid = l + (r-l)/2;

        if (ok(mid)) r = mid;
        else l = mid + 1;
    }

    if (l == INF){
        cout << -1 << "\n";
        return;
    }

    vector<int> path;
    for (int p = n-1; p != 0; p = pai[p]){
        path.push_back(p);
    }
    path.push_back(0);

    reverse(path.begin(), path.end());

    cout << path.size() - 1 << "\n";
    for (int i = 0; i < path.size(); i++){
        cout << path[i] + 1 << " \n"[i == path.size()-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
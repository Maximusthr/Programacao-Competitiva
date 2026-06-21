#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> proj(n);
    for (auto &i : proj) cin >> i;

    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        deg[y]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++){
        if (deg[i] == 0) pq.push({proj[i], i});
    }

    vector<int> topo;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        topo.push_back(u);

        for (auto v : g[u]){

            deg[v]--;
            if (deg[v] == 0){
                pq.push({proj[v], v});
            }
        }
    }

    if (topo.size() != n){
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < n; i++){
        cout << topo[i] + 1 << " \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
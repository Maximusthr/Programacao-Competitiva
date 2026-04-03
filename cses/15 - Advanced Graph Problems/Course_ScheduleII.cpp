#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> deg(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[y].push_back(x);
        deg[x]++;
    }

    priority_queue<int> pq;
    for (int i = 0; i < n; i++){
        if (deg[i] == 0) pq.push(i);
    }

    vector<int> topo;

    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        topo.push_back(u);
        for (auto v : g[u]){
            deg[v]--;
            if (deg[v] == 0) pq.push(v);
        }
    }

    reverse(topo.begin(), topo.end());

    for (auto &i : topo) cout << i+1 << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
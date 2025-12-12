#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<int> prod(n);
    for (auto &i : prod) {
        cin >> i;
        i--;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> dist(n, -1);
    
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for (auto v : g[u]){
            if (dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    vector<priority_queue<int>> city(k);
    for (int i = 0; i < n; i++){
        city[prod[i]].push(dist[i]);
    }

    for (int i = 0; i < k; i++){
        cout << city[i].top() << " \n"[i==n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
        solve();
    // }
}
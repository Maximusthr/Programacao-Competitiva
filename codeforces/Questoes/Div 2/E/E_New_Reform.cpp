#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<vector<int>> g(n);
    for (int i = 0; i < k; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    queue<int> q;
    vector<int> viz(n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        viz[i] = g[i].size();
        if (g[i].size() == 1) q.push(i);
        else if (g[i].size() == 0) ans++;
    }

    vector<bool> vis(n);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        if (vis[u]) continue;
        vis[u] = true;

        for (auto v : g[u]){
            if (vis[v]) continue;

            if (viz[v] == 1){
                ans++;
            }

            viz[v]--;
            if (viz[v] == 1) q.push(v);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}


#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int c = 1;

void solve(){
    cout << "Scenario #" << c << ":\n";
    
    int n, m; cin >> n >> m;

    //R1 and R2, meaning that “employee R1 is lower than employee R2's rank”
    
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        swap(x, y);
        g[x].push_back(y);
        deg[y]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++){
        if (deg[i] == 0) q.push(i);
    }
    
    vector<int> topo;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (auto v : g[u]){
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    vector<int> vis(n);

    int x = 1;
    int temp = 0;

    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++){
        for (auto v : g[topo[i]]){
            vis[v] = max(vis[v], vis[topo[i]] + 1);
        }

        ans.push_back({vis[topo[i]] + 1, topo[i]});
    }

    sort(ans.begin(), ans.end(), [&](pair<int, int> x, pair<int, int> y){
        if (x.first != y.first) return x.first < y.first;
        return x.second < y.second;
    });

    for (int i = 0; i < n; i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    c++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
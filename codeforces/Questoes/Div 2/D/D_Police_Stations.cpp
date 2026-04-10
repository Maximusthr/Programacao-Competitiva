#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k, d; cin >> n >> k >> d;

    vector<int> est(k);
    vector<int> dist(n, INF);
    queue<pair<int, int>> q;
    for (auto &i : est) {
        cin >> i;
        i--;
        if (dist[i] == INF){
            dist[i] = 0;
            q.push({i, -1});
        }
    }

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back({y, i});
        g[y].push_back({x, i});
    }
    
    vector<int> ans;
    vector<bool> id(n);
    while(!q.empty()){
        auto [u, pai] = q.front();
        q.pop();

        for (auto [v, idx] : g[u]){
            if (v == pai) continue;
            if (dist[v] != INF){
                if (dist[u] + 1 >= dist[v]){
                    if (!id[idx]){
                        ans.push_back(idx);
                        id[idx] = true;
                    }
                }
            }
            else {
                dist[v] = dist[u] + 1;
                q.push({v, u});
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto &i : ans) cout << i + 1 << " ";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
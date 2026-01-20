#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<vector<pair<int, int>>> g(n);

    for (int i = 0; i < n-1; i++){
        int x, y, c; cin >> x >> y >> c;

        g[x].push_back({y, c});
        g[y].push_back({x, c});
    }

    int ans = 0;

    auto dfs = [&](auto &&self, int u, int c, int p) -> void {
        ans = max(ans, c);
        
        for (auto [v, w] : g[u]){
            if (v != p){
                self(self, v, c + w, u);
            }
        }
        

    };

    dfs(dfs, 0, 0, -1);

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
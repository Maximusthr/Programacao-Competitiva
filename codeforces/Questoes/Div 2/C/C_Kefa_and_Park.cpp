#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> cat;
vector<vector<int>> g;
vector<bool> vis;

int n, k;
int ans = 0;

void dfs(int u){
    if (!vis[u]) vis[u] = true;

    if (g[u].size() == 1 && u != 0) ans++;

    for (auto v : g[u]){
        if (!vis[v]){
            cat[v] += cat[u];
            if (cat[v] > k) {
                vis[v] = true;
                continue;
            }
            else {
                if (cat[v]-cat[u] == 0){
                    cat[v] = 0;
                }
                dfs(v);
            }
        }
    }
}

void solve(){
    cin >> n >> k;

    cat.resize(n);
    for (auto &i : cat) cin >> i;

    g.resize(n);
    vis.resize(n);

    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0);

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}
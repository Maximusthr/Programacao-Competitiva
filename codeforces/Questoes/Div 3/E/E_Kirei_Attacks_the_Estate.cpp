#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    vector<bool> vis(n);
    vector<ll> v(n);
    
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<ll> ans(n, -LINF);

    ll aux = 0;

    auto dfs = [&](auto self, int u, ll sum, int sig) -> void {
        if (!vis[u]) vis[u] = true;

        // vale a pena somar ou continuar com o valor dele?
        if (sig < 0){
            sum -= v[u];
        }
        else {
            sum = max(sum + v[u], v[u]);
            ans[u] = max(ans[u], sum);  
        }


        for (auto w : g[u]){
            if (!vis[w]){
                self(self, w, sum, sig * -1);   
            }
        }
    };

    dfs(dfs, 0, 0, 1);
    vis.assign(n, false);
    dfs(dfs, 0, 0, -1);

    for (int i = 0; i < n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
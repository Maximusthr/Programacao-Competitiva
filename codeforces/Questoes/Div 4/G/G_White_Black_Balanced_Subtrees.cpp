#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);

    for (int i = 1; i < n; i++){
        int x; cin >> x;
        x--;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    string s; cin >> s;

    vector<int> B(n);
    vector<int> W(n);

    auto dfs = [&](auto self, int u, int e) -> void {
        if (s[u] == 'W') W[u] = 1;
        else B[u] = 1;

        for (auto v : g[u]){
            if (v != e){
                self(self, v, u);
                W[u] += W[v];
                B[u] += B[v];
            }
        }
    };

    dfs(dfs, 0, -1);

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (B[i] > 0 && B[i] == W[i]) ans++;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
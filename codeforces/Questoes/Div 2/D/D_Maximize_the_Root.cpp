#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> pts(n);
    vector<vector<int>> g(n);
    for (auto &i : pts) cin >> i;
    for (int i = 1; i < n; i++){
        int x; cin >> x;
        x--;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    auto dfs = [&](auto &&self, int u, int p) -> void {
        for (auto v : g[u]){
            if (v == p) continue;
            self(self, v, u);
        }

        int c = INF;
        for (auto v : g[u]){
            if (v == p) continue;
            c = min(c, pts[v]);
        }

        if (c == INF) return;
        if (u != 0){
            if (pts[u] > c) pts[u] = c;
            else pts[u] = pts[u] + abs((pts[u] - c)/2);
        }
        else {
            pts[u] += c;
        }
    };

    dfs(dfs, 0, -1);

    cout << pts[0] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
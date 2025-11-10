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
    }
    
    vector<int> leafs(n);

    auto dfs = [&](auto self, int u, int p) -> void {
        if (g[u].size() == 0){
            leafs[u] = -1;
            leafs[p]++;
        }

        for (auto v : g[u]){
            self(self, v, u);
        }
    };

    dfs(dfs, 0, -1);

    for (int i = 0; i < n; i++){
        if (leafs[i] != -1 && leafs[i] <= 2) {
            cout << "No" << "\n";
            return;
        }
    }

    cout << "Yes" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
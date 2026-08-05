#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve
void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++){
        int x; cin >> x;
        x--;
        g[x].push_back(i);
    }

    vector<int> val(n);
    for (auto &i : val) cin >> i;

    vector<int> ans(n);
    vector<int> lis = {-INF};
    
    auto dfs = [&](auto &&self, int u, int p) -> void {
        auto it = lower_bound(lis.begin(), lis.end(), val[u]) - lis.begin();
        
        bool fim = false;
        int last = 0;
        if (it == lis.size()) {
            lis.push_back(val[u]);
            fim = true;
        }
        else {
            last = lis[it];
            lis[it] = val[u];
        }

        for (auto v : g[u]){
            self(self, v, u);
        }

        ans[u] = lis.size() - 1;

        if (fim) lis.pop_back();
        else lis[it] = last;
    };

    dfs(dfs, 0, -1);

    for (int i = 1; i < n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct P {
    ll u, a, b;
};

void solve(){
    int n; cin >> n;

    vector<vector<P>> g(n);
    for (int i = 1; i < n; i++){
        int x, a, b; cin >> x >> a >> b;
        x--;
        g[x].push_back({i, a, b});
        g[i].push_back({x, a, b});
    }

    vector<ll> sum;
    vector<int> ans(n);
    auto dfs = [&](auto &&self, int u, int p, ll a, ll b) -> void {
        if (p != -1){
            sum.push_back(b);
            auto it = upper_bound(sum.begin(), sum.end(), a) - sum.begin();
            ans[u] = it;
        }

        for (auto [v, a1, b1] : g[u]){
            if (v == p) continue;
            self(self, v, u, a + a1, b + b1);
        }

        sum.pop_back();
    };
    
    dfs(dfs, 0, -1, 0, 0);

    for (int i = 1; i < n; i++){
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

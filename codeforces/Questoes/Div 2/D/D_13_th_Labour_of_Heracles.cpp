#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    ll sum = 0;
    vector<pair<ll, ll>> w(n);
    for (int i = 0; i < n; i++){
        cin >> w[i].first;
        w[i].second = i;
        sum += w[i].first;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<ll> ss;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        if (g[u].size() >= 2){
            for (int i = 0; i < g[u].size() - 1; i++){
                ss.push_back(w[u].first);
            }
        }
        for (auto v : g[u]){
            if (v != p){
                self(self, v, u);
            }
        }
    };

    dfs(dfs, 0, -1);
    sort(ss.begin(), ss.end(), greater<ll> ());

    cout << sum << " ";
    for (int i = 0; i < ss.size(); i++){
        sum += ss[i];
        cout << sum << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+5;

int n, k;
vector<vector<int>> g(MAX);
vector<int> sz;

ll ans = 0;
void dfs(int u, int p){
    sz[u] = 1;

    for (auto v : g[u]){
        if (v != p){
            dfs(v, u);
            sz[u] += sz[v];
        }
    }

    if (sz[u] >= k) ans += (n - sz[u]);

    if (n - sz[u] >= k) ans += sz[u];
}

void solve(){
    cin >> n >> k;
    g.clear();
    sz.clear();

    g.resize(n, vector<int> ());
    sz.resize(n);

    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, -1);

    ans += n;
    cout << ans << "\n";
    ans = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
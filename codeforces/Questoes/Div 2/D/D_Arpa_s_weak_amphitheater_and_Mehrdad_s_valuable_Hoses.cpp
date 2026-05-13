#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1005;

struct DSU {
    int n;
    vector<int> p, sz, beauty, peso;

    DSU(vector<int> &beaut, vector<int> &pes) : n(beaut.size()), p(n), sz(n, 1), beauty(n), peso(n){
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < n; i++){
            peso[i] = pes[i];
            beauty[i] = beaut[i];
        }
    }

    int get(int a){
        if (a != p[a]) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a), b = get(b);
        if (a == b) return;

        if (sz[a] > sz[b]) swap(a, b);

        p[a] = b;
        sz[b] += sz[a];
        beauty[b] += beauty[a];
        peso[b] += peso[a];
    }
};

void solve(){
    int n, m, w; cin >> n >> m >> w;
    vector<int> grupos;
    vector<int> peso(n), beauty(n);
    vector<vector<int>> g(n);

    for (int i = 0; i < n; i++) cin >> peso[i];
    for (int i = 0; i < n; i++) cin >> beauty[i];
    
    DSU dsu(beauty, peso);
    
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        dsu.merge(x, y);
    }

    set<int> tem;
    for (int i = 0; i < n; i++){
        int x = dsu.get(i);
        tem.insert(x);
    }

    grupos = {tem.begin(), tem.end()};
    g.resize(n);

    for (int i = 0; i < n; i++){
        int x = dsu.get(i);
        g[x].push_back(i);
    }
    
    int dp[w+1];
    
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < grupos.size(); i++){
        int idx = dsu.get(grupos[i]);
        int x = dsu.peso[idx];

        for (int W = 0; W <= w; W++){

            if (W - x >= 0) {
                dp[W - x] = max(dp[W - x], dp[W] + dsu.beauty[idx]);
            }

            for (auto v : g[idx]){
                if (W - peso[v] >= 0){
                    dp[W - peso[v]] = max(dp[W - peso[v]], dp[W] + beauty[v]);
                }
            }
        }   
    }
    
    cout << dp[0] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
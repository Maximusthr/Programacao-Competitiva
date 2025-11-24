#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Edge {
    int x, y, c;

    bool operator<(Edge const &P) {
        return c < P.c;
    }
};

struct DSU {
    vector<int> p, sz;

    DSU (int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    };

    int get(int a){
        if (a != p[a]){
            p[a] = get(p[a]);
        }

        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);

        if (a == b) return;

        if (sz[a] > sz[b]) swap(a, b);

        p[a] = p[b];
        sz[b] += sz[a];
    }
};

void solve(){
    int n, m; cin >> n >> m;
    
    vector<Edge> Edg(m);
    
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;

        Edg[i].x = x;
        Edg[i].y = y;
        Edg[i].c = w;
    }

    sort(Edg.begin(), Edg.end());

    vector<vector<int>> g(n);
    vector<bool> vis(n);
    
    ll ans = 0;
    DSU dsu(n);
    for (int i = 0; i < m; i++){
        if (dsu.get(Edg[i].x) != dsu.get(Edg[i].y)){
            ans += Edg[i].c;
            dsu.merge(Edg[i].x, Edg[i].y);

            g[Edg[i].x].push_back(Edg[i].y);
            g[Edg[i].y].push_back(Edg[i].x);
        }
    }

    // bastava saber se: sz[1] == n-1 :)
    auto dfs = [&](auto &&self, int u, int &comp) -> void {
        if (!vis[u]) {
            vis[u] = true;
            comp++;
        }

        for (auto v : g[u]){
            if (!vis[v]){
                self(self, v, comp);
            }
        }
    };

    int tem = 0;
    dfs(dfs, 0, tem);

    if (tem == n){
        cout << ans << "\n";
    }
    else cout << "IMPOSSIBLE" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
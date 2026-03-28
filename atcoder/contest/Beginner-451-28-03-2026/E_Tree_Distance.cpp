#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz;

    DSU (int n) : p(n), sz(n, 1){
        iota(p.begin(), p.end(), 0);
    };

    int get(int a){
        if (p[a] != a) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a), b = get(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
    }
};

struct Edges{
    int x, y, w;

    bool operator<(Edges const P) const {
        return (w < P.w);
    };
};

void solve(){
    int n; cin >> n;

    vector<vector<int>> mat(n, vector<int> (n));
    vector<vector<bool>> vale(n, vector<bool> (n));
    vector<Edges> g;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            cin >> mat[i][j];
            g.push_back({i, j, mat[i][j]});
        }
    }

    sort(g.begin(), g.end());

    DSU dsu(n);
    vector<Edges> mark;
    for (int i = 0; i < g.size(); i++){
        int x = g[i].x;
        int y = g[i].y;

        int aux = x, auy = y;

        x = dsu.get(x), y = dsu.get(y);
        if (x == y) continue;
        dsu.merge(x, y);
        mark.push_back({aux, auy, g[i].w});
    }

    vector<vector<pair<int, int>>> graf(n);
    for (int i = 0; i < n-1; i++){
        int x = mark[i].x;
        int y = mark[i].y;
        int w = mark[i].w;

        graf[x].push_back({y, w});
        graf[y].push_back({x, w});
    }

    vector<bool> vis(n);

    auto dfs = [&](auto &&self, int u, int c, int start) -> void {
        if (!vis[u]) vis[u] = true;

        for (auto [v, w] : graf[u]){
            if (!vis[v]){
                self(self, v, c + w, start);
            }
        }

        if (mat[u][start] == c) vale[u][start] = true;
        if (mat[start][u] == c) vale[start][u] = true;
    };

    for (int i = 0; i < n; i++){
        vis.assign(n, false);
        dfs(dfs, i, 0, i);
    }

    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if (!vale[i][j]){
                cout << "No" << "\n";
                return;
            }
        }
    }

    cout << "Yes" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
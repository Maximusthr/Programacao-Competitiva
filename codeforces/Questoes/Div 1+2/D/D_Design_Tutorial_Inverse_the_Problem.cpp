#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz;
    int comp;

    DSU (int n) : p(n), sz(n, 1){
        comp = 0;
        iota(p.begin(), p.end(), 0);
    };

    int get(int a){
        if (a != p[a]) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        p[a] = p[b];
        comp++;
    }
};

void solve(){
    int n; cin >> n;

    struct Edges {
        int u, v;
        ll w;
        bool operator<(Edges const P) const {
            return w < P.w;
        };
    };

    vector<vector<ll>> mat(n, vector<ll> (n));
    vector<Edges> edg;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
            if (i == j && mat[i][j] != 0) {
                cout << "NO" << "\n";
                return;
            }
            if (mat[i][j] != 0){
                edg.push_back({i, j, mat[i][j]});
            }
        }
    }

    sort(edg.begin(), edg.end());

    DSU dsu(n);
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < edg.size(); i++){
        if (dsu.comp == n-1) break;
        int u = edg[i].u;
        int v = edg[i].v;
        int uu = dsu.get(u);
        int vv = dsu.get(v);
        if (uu == vv) continue;
        dsu.merge(uu, vv);

        g[u].push_back({v, edg[i].w});
        g[v].push_back({u, edg[i].w});
    }

    if (dsu.comp != n-1){
        cout << "NO" << "\n";
        return;
    }

    vector<ll> dist(n, -1);
    auto bfs = [&](int u) -> void {
        queue<int> q;
        q.push(u);
        dist[u] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for (auto [v, w] : g[u]){
                if (dist[v] == -1){
                    dist[v] = dist[u] + w;
                    q.push(v);
                }
            }
        }
    };

    for (int i = 0; i < n; i++){
        bfs(i);

        for (int j = 0; j < n; j++){
            if (mat[i][j] != dist[j]){
                cout << "NO" << "\n";
                return;
            }
        }

        dist.assign(n, -1);
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
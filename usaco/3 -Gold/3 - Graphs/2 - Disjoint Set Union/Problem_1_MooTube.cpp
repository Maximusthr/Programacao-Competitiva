#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Edges {
    int x, y, w;

    bool operator <(const Edges &edg) {
        if (w != edg.w) return w > edg.w;
        if (x != edg.x) return x < edg.x;
        return y < edg.y;
    };
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
        p[a] = b;
        sz[b] += sz[a];
    }
};

struct Ordem {
    int k, x, pos;
};

void solve(){
    int n, q; cin >> n >> q;

    vector<Edges> adj;
    for (int i = 0; i < n-1; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        adj.push_back({x, y, w});
    }

    sort(adj.begin(), adj.end());

    vector<Ordem> queries(q);
    for (int i = 0; i < q; i++){
        int k, x; cin >> k >> x;
        x--;

        queries[i] = {k, x, i};
    }

    sort(queries.begin(), queries.end(), [&](Ordem x, Ordem y){
        return x.k > y.k;
    });
    
    DSU dsu(n);
    vector<pair<int, int>> ans;

    int j = 0;
    for (int i = 0; i < q; i++){
        while (j < n-1 && adj[j].w >= queries[i].k){
            dsu.merge(adj[j].x, adj[j].y);
            j++;
        }
        ans.push_back({queries[i].pos, dsu.sz[dsu.get(queries[i].x)] - 1});
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    solve();
}
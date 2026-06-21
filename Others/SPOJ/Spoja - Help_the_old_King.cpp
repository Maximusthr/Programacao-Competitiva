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

    int get(int u){
        if (u != p[u]) p[u] = get(p[u]);
        return p[u];
    }

    void merge(int a, int b){
        a = get(a), b = get(b);
        if (a == b) return;

        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
    }
};

struct Edges {
    int u, v;
    ll w;

    bool operator<(const Edges &p) const {
        return w < p.w;
    };
};

void solve(){
    int n, m; cin >> n >> m;

    vector<Edges> g(m);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        ll w; cin >> w;
        g[i] = {x, y, w};
    }

    sort(g.begin(), g.end());

    int custo = 1;
    DSU dsu(n);
    for (int i = 0; i < m; i++){
        int x = dsu.get(g[i].u);
        int y = dsu.get(g[i].v);
        if (x == y) continue;

        dsu.merge(x, y);
        custo += __builtin_ctzll(g[i].w);
    }

    cout << custo << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
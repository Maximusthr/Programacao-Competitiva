#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz;

    DSU (int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    };

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
    }

    void clear(){
        iota(p.begin(), p.end(), 0);
        sz.assign(sz.size(), 1);
    }
};

struct Edges {
    ll u, v, w;
};

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<Edges> g(m);
    for (int i = 0; i < m; i++){
        ll x, y, w; cin >> x >> y >> w;
        x--, y--;
        g[i] = {x, y, w};
    }   

    sort(g.begin(), g.end(), [&](Edges x, Edges y){
        return x.w < y.w;
    });

    // mst que pega o melhor custo
    int best = INF;
    int idx = 0;
    for (int i = 0; i < m; i++){
        int x = abs(k - g[i].w);
        
        if (x < best){
            best = x;
            idx = i;
        }
    }

    ll ans = best;

    DSU dsu(n);
    dsu.merge(g[idx].u, g[idx].v);

    for (int i = 0; i < m; i++){
        ll x = dsu.get(g[i].u);
        ll y = dsu.get(g[i].v);
        if (x == y) continue;

        if (g[i].w > k) ans += g[i].w - k;

        dsu.merge(x, y);
    }

    // mst que pega o maior custo a partir de w >= k
    best = INF;
    idx = 0;
    for (int i = 0; i < m; i++){
        if (g[i].w < k) continue;

        if (g[i].w - k < best){
            best = g[i].w - k;
            idx = i;
            break;
        }
    }

    ll ans2 = best;

    dsu.clear();
    dsu.merge(g[idx].u, g[idx].v);

    for (int i = 0; i < m; i++){
        ll x = dsu.get(g[i].u);
        ll y = dsu.get(g[i].v);
        if (x == y) continue;

        if (g[i].w > k) ans2 += g[i].w - k;

        dsu.merge(x, y);
    }

    // mst padrao

    dsu.clear();
    ll ans3 = 0;
    ll maior = 0;

    for (int i = 0; i < m; i++){
        ll x2 = dsu.get(g[i].u);
        ll y2 = dsu.get(g[i].v);

        if (x2 == y2) continue;

        if (g[i].w > k) ans3 += g[i].w - k;
        dsu.merge(x2, y2);
        maior = max(g[i].w, maior);
    }

    if (maior < k) {
        ans3 += k - maior;
    }

    cout << min({ans, ans2, ans3}) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
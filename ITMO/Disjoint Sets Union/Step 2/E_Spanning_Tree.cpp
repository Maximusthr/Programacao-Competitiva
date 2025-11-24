#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Edges {
    int x, y, w;

    bool operator<(Edges &P) const {
        return w < P.w;
    };
};

struct DSU {
    vector<int> p, sz;

    DSU(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    };

    int get(int a){
        if (p[a] != a){
            p[a] = get(p[a]);
        }

        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);

        if (a == b) return;

        if (sz[a] > sz[b]){
            swap(a, b);
        }

        p[a] = p[b];
        sz[b] += sz[a];
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<Edges> g(m);
    for (int i = 0; i < m; i++){
        cin >> g[i].x >> g[i].y >> g[i].w;
        g[i].x--, g[i].y--;
    }

    sort(g.begin(), g.end());

    DSU dsu(n);

    ll ans = 0;
    for (int i = 0; i < m; i++){
        int a = dsu.get(g[i].x);
        int b = dsu.get(g[i].y);

        if (a == b) continue;

        ans += g[i].w;

        dsu.merge(a, b);
    }

    cout << ans << "\n";
}
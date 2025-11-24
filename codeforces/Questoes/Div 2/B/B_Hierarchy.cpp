#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Edge {
    int x, y, custo;

    bool operator<(Edge const& P) {
        return custo < P.custo;
    };
};

struct DSU {
    vector<int> p, sz;

    DSU (int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    };

    int get (int a){
        if (a != p[a]) p[a] = get(p[a]);

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
    int n; cin >> n;
    
    vector<int> app(n);
    for (int i = 0; i < n; i++){
        cin >> app[i];
    }
    
    int m; cin >> m;
    vector<Edge> edge;
    for (int i = 0; i < m; i++){
        int x, y, c; cin >> x >> y >> c;
        x--, y--;
        edge.push_back({x, y, c});
    }
    
    sort(edge.begin(), edge.end());

    DSU dsu(n);
    ll ans = 0;
    int tudo = n;
    
    vector<bool> vis(n);
    for (auto [x, y, c] : edge){
        if (!vis[y]) {
            if (dsu.get(x) != dsu.get(y)){
                ans += c;
                tudo--;
    
                dsu.merge(x, y);
            }
        }
        vis[y] = true;
    }

    cout << (tudo > 1 ? -1 : ans) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
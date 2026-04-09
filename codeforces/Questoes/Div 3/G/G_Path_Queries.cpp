#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p;
    vector<ll> sz;

    DSU (int n) : p(n), sz(n, 1){
        iota(p.begin(), p.end(), 0);
    }

    int get(int a){
        if (p[a] != a) p[a] = get(p[a]);
        return p[a];
    }

    bool merge(int a, int b){
        a = get(a);
        b = get(b);

        if (a == b) return false;

        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
        return true;
    }
};

struct Edges {
    int u, v, w;

    bool operator<(const Edges &P) const {
        return w < P.w;
    };
};

void solve(){
    int n, q; cin >> n >> q;

    vector<Edges> g;
    for (int i = 0; i < n-1; i++){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        g.push_back({u, v, w});
    }

    sort(g.begin(), g.end());

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++){
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(queries.begin(), queries.end());

    ll sum = 0;
    vector<ll> ans(q);
    DSU dsu(n);
    for (int i = 0, j = 0; i < q; i++){
        if (j == n-1){
            while (i < q){
                ans[queries[i].second] = sum;
                i++;
            }
            break;
        }

        while(j < n-1 && g[j].w <= queries[i].first){
            int u = dsu.get(g[j].u);
            int v = dsu.get(g[j].v);

            if (u == v) {
                j++;
                continue;
            }

            ll uu = dsu.sz[u] * (dsu.sz[u]-1)/2;
            ll vv = dsu.sz[v] * (dsu.sz[v]-1)/2;
            sum -= uu;
            sum -= vv;

            dsu.merge(u, v);
            u = dsu.get(g[j].u);

            sum += dsu.sz[u] * (dsu.sz[u]-1)/2;
            j++;
        }   

        ans[queries[i].second] = sum;
    }

    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
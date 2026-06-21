#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz;
    int comp;
    
    DSU (int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
        comp = n;
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
        comp--;
    }
};

void solve(){
    int n, m; cin >> n >> m;

    vector<pair<int, int>> g(m);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[i] = {x, y};
    }

    int q; cin >> q;
    vector<int> queries(q);
    set<int> tipo;
    for (auto &i: queries) {
        cin >> i;
        i--;
        tipo.insert(i);
    }

    DSU dsu(n);
    for (int i = 0; i < m; i++){
        if (tipo.count(i)) continue;

        dsu.merge(dsu.get(g[i].first), dsu.get(g[i].second));
    }

    vector<int> ans;

    for (int i = q-1; i >= 0; i--){
        ans.push_back(dsu.comp);
        
        int x = g[queries[i]].first;
        int y = g[queries[i]].second;

        x = dsu.get(x);
        y = dsu.get(y);

        dsu.merge(x, y);
    }

    reverse(ans.begin(), ans.end());
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
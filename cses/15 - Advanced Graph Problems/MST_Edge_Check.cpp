#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Edges{
    int x, y, w, id;
    
    bool operator<(Edges const &W) const {
        return w < W.w;
    }
};

struct Dsu{
    vector<int> p, sz;

    Dsu(int n) : p(n), sz(n, 1){
        iota(p.begin(), p.end(), 0);
    }

    int get(int a){
        if (a != p[a]) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a), b = get(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        p[a] = p[b];
        sz[b] += sz[a];
    }
};

void solve(){
    int n, m; cin >> n >> m;

    vector<Edges> edge;
    set<int> pesos;
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        edge.push_back({x, y, w, i});
        pesos.insert(w);
    }

    sort(edge.begin(), edge.end());

    Dsu dsu(n);
    vector<bool> ids(m);

    map<int, vector<Edges>> mapa;
    for (int i = 0; i < m; i++){
        auto x = edge[i];
        mapa[x.w].push_back(edge[i]);
    }

    vector<int> p = {pesos.begin(), pesos.end()};

    for (int i = 0; i < p.size(); i++){
        for (auto tipo : mapa[p[i]]){
            int u = dsu.get(tipo.x);
            int v = dsu.get(tipo.y);

            if (u != v){
                ids[tipo.id] = true;
            }
        }
        for (auto tipo : mapa[p[i]]){
            dsu.merge(tipo.x, tipo.y);
        }
    }

    for (int i = 0; i < m; i++){
        cout << (ids[i] ? "YES" : "NO") << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
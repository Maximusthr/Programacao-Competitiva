#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct Edges{
    int x, y, w;
};

struct Dsu{
    vector<int> p, sz;
    int comp;

    Dsu(int n) : p(n), sz(n, 1) {
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
        p[a] = p[b];
        sz[b] += sz[a];
        comp--;
    }
};

void solve(){
    int n, m; cin >> n >> m;

    vector<Edges> g;
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        g.push_back({x, y, w});
    }

    sort(g.begin(), g.end(), [&](Edges E, Edges F){
        return E.w < F.w;
    });

    ll dif = LINF;
    for (int i = 0; i < m; i++){
        Dsu dsu(n);
        int v = g[i].w;
        for (int j = i; j < m; j++){
            auto [a, b, w] = g[j];

            a = dsu.get(a), b = dsu.get(b);
            if (a == b) continue;

            dsu.merge(a, b);
            if (dsu.comp == 1){
                dif = min(dif, 1ll * (w - v));
                break;
            }
        }
    }

    if (dif == LINF){
        cout << "NO" << "\n";
    }
    else {
        cout << "YES" << "\n";
        cout << dif << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
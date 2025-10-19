#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p;
    vector<int> sz;

    DSU (int n) : p(n), sz(n, 1){
        iota(p.begin(), p.end(), 0);
    };

    int get(int a){
        if (a != p[a]){
            p[a] = get(p[a]);
        }

        return p[a];
    }

    bool equal(int a, int b){
        return (get(a) == get(b));
    }

    bool merge(int a, int b){
        a = get(a);
        b = get(b);

        if (a == b) return 0;

        if (sz[a] > sz[b]){
            swap(a, b);
        }
        p[a] = b;
        sz[b] += sz[a];
        
        return 1;
    }
};

void solve(){
    int n, f, g;
    cin >> n >> f >> g;

    vector<pair<int, int>> F(f);
    for (int i = 0; i < f; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        if (x > y) swap(x, y);
        F[i] = {x, y};
    }

    vector<pair<int, int>> G(g);
    for (int i = 0; i < g; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        if (x > y) swap(x, y);
        G[i] = {x, y};
    }

    DSU dsuF(n), dsuG(n);

    int ans = 0;

    int cmpg = n;
    for (int i = 0; i < g; i++){
        cmpg -= dsuG.merge(G[i].first, G[i].second);
    }

    int cmpf = n;
    for (int i = 0; i < f; i++){
        if (dsuG.equal(F[i].first, F[i].second)){
            cmpf -= dsuF.merge(F[i].first, F[i].second);
        }
        else ans++;
    }

    cout << ans + cmpf - cmpg << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}